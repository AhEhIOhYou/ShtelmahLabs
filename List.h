#include <iostream>
using namespace std;
#include "Node.h"

template <typename MyItType>
//класс итератора для нашего односвязного списка
class IteratorForList {
private:
    //единственная классовая переменная - указатель на текущий элемент
    Node<MyItType>* element;
public:

    //предопределяем типы итератора
    iterator <input_iterator_tag, MyItType, ptrdiff_t, const MyItType*, const MyItType&>

    //конструктор дефолтный.......
    ListIterator() { }

    //конструктор покруче со входным значением
    IteratorForList(Node<MyItType>* inElement) : element(inElement) { }

    //перегруженные операторы пошли дальше

    //значение текущего узла
    MyItType& operator*() const {
        return element->data;
    }

    //указатель для структур и объектов
    const MyItType* operator->() const {
        return &element->data;
    }

    //переход к следующему узлу
    IteratorForList& operator++() {
        element = element->nextPtr;
        return *this;
    }

    //проверка на равенство
    bool operator==(IteratorForList const& r) {
        return (element == r.element);
    }

    //проверка на неравенство
    bool operator!=(IteratorForList const& r) {
        return (element != r.element);
    }

};

template <typename MyNodeType>

class List {
public:
    
    //определеяем основные функции и резервируем имя для итератора
    typedef IteratorForList<MyNodeType> iterator;
    List();
    List(const int);
    ~List();
    void addFront(const MyNodeType&);
    void addBack(const MyNodeType&);
    bool deleteFront(MyNodeType&);
    bool deleteBack(MyNodeType&);
    bool empty() const;
    void print() const;
    void Revers();

    //инициализируем итераторы для класс начала - первый элемент, и конца - пустота
    IteratorForList<MyNodeType> begin() {
        return IteratorForList<MyNodeType>(firstPtr);
    }

    IteratorForList<MyNodeType> end() {
        return IteratorForList<MyNodeType>(nullptr);
    }

private:
    //переменные внутри класса - указатели на первый и последний узел
    Node <MyNodeType>* firstPtr;
    Node <MyNodeType>* lastPtr;
    //для указателя на новый узел, нужно только внутри класса
    Node <MyNodeType>* getNewNode(const MyNodeType&);

};

template <typename MyNodeType>
//дефолтный конструктор
List<MyNodeType>::List(): firstPtr(0), lastPtr(0) { }

template <typename MyNodeType>
//конструктор с количеством ячеек
List<MyNodeType>::List(const int count) {
    for (int i = 0; i < count ; i++) {
        addBack(0);
    }
}

template <typename MyNodeType>
//деструкторик
List <MyNodeType>::~List() {

    if (!empty()) {

        Node <MyNodeType>* currentPtr = firstPtr;
        Node <MyNodeType>* tempPtr;

        while (currentPtr != 0) {
            tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }

    }
}


template <typename MyNodeType>
//вставка узла в начало
void List <MyNodeType>::addFront(const MyNodeType& value) {
    Node<MyNodeType>* newPtr = getNewNode(value);

    if (empty()) {
        firstPtr = lastPtr = newPtr; //список имеет 1 узел
    }
    else {
        newPtr->nextPtr = firstPtr; //новый указывает на предудущий
        firstPtr = newPtr;
    }
}

template<typename MyNodeType>
//вставка узла в конец
void List<MyNodeType>::addBack(const MyNodeType& value) {

    Node<MyNodeType>* newPtr = getNewNode(value);

    if (empty()) {
        firstPtr = lastPtr = newPtr; //список имеет всего один узел
    }
    else {
        lastPtr->nextPtr = newPtr;//обновить бывший последнйи узел
        lastPtr = newPtr;//новый последний узел
    }

}

template<typename MyNodeType>
//удаление головного узла
bool List<MyNodeType>::deleteFront(MyNodeType& value) {
    if (empty()) {
        return false;
    }
    else {
        Node <MyNodeType>* tempPtr = firstPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else
            firstPtr = firstPtr->nextPtr;

            value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

template<typename MyNodeType>
//удаление последнего узла
bool List <MyNodeType>::deleteBack(MyNodeType& value) {
    if (empty()) {
        return false;
    }
    else {
        Node<MyNodeType>* tempPtr = lastPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else {
            Node <MyNodeType>* currentPtr = firstPtr;

            while (currentPtr->nextPtr != lastPtr)
                currentPtr = currentPtr->nextPtr;

            lastPtr = currentPtr;
            currentPtr->nextPtr = 0;
        }
        value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

template<typename MyNodeType>
//првоерка на пустоту
bool List < MyNodeType >::empty() const {
    return firstPtr == 0;
}

template<typename MyNodeType>
//указатель на новый узел
Node <MyNodeType>* List<MyNodeType>::getNewNode(const MyNodeType& value) {
    return new Node<MyNodeType>(value);
}


template<typename MyNodeType>
//печать списка
void List<MyNodeType>::print() const {
    if (empty()) {
        cout << "Список пустой" << endl;
        return;
    } else {
        Node < MyNodeType >* currentPtr = firstPtr;
        cout << "Список: ";
        
        while (currentPtr !=  nullptr) {
            cout << currentPtr->data << ' ';
            currentPtr = currentPtr->nextPtr;
        }
        cout << endl;
    }
}

template<typename MyNodeType>
//прокаченная сортировка-реверс
void List<MyNodeType>::Revers() {
    cout << "Реверс: ";
    if (empty()) {
        cout << "Пусто" << endl;
    }
    else {
        Node <MyNodeType>* tempPtr = nullptr;

        while (firstPtr) {
            Node <MyNodeType>* currentPtr = firstPtr;

            firstPtr = firstPtr->nextPtr;
            currentPtr->nextPtr = tempPtr;
            tempPtr = currentPtr;
        }
        firstPtr = tempPtr;
    }
}