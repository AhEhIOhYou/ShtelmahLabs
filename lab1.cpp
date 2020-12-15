#include <iostream>
using namespace std;

template <typename T>
struct node
{
    T item;
    node<T>* next;
};

template <typename T>
class stack
{
private:
    //вершина стека
    node<T>* stackTop;

public:
    // конструктор по умолчанию
    stack() {
        stackTop = nullptr;
    }

    // конструктор копровання
    stack(const stack& SL)
    {
        node<T>* p;
        node<T>* p2;
        node<T>* p3;

        //инициализация вершины
        stackTop = nullptr;
        p3 = nullptr;

        p = SL.stackTop; // указатель p движется по списку SL.pTop->...
        while (p != nullptr)
        {
            // 1. создаем узелок p2  
            p2 = new node<T>;
            p2->item = p->item;
            p2->next = nullptr;

            // 2. вершина = старая вершина + p2
            if (stackTop == nullptr) // создаем очередь
            {
                stackTop = p2;
                p3 = p2;
            }
            else
            {
                p3->next = p2;
                p3 = p3->next;
            }

            // 3. перейти на следующий элемент
            p = p->next;
        }
    }

    //помещаем элемент в начало стека
    void pushFront(T item)
    {
        node<T>* p;

        // 1. cформировать элемент
        p = new node<T>;
        p->item = item;
        p->next = stackTop; //p указывает на 1-й элемент

        // 2. Перенаправить вершину на p
        stackTop = p;
    }

    // чистим стек
    void clean()
    {
        node<T>* p;
        node<T>* p2;

        p = stackTop;

        while (p != nullptr)
        {
            p2 = p; // сделать копию из p
            p = p->next; // перейти на следующий элемент стека
            delete p2; // удалить память, выделенную для предыдущего элемента
        }
        stackTop = nullptr; // и почистить вершину
    }

    // вывод стека
    void print()
    {
        cout << "Стек: " << endl;
        if (stackTop == nullptr) {
            cout << "Стек пустой" << endl;
        }
        else
        {
            node<T>* p; // дополнительный указатель
            p = stackTop;
            while (p != nullptr)
            {
                cout << p->item << "\t";
                p = p->next;
            }
            cout << endl;
        }
    }

    //функция реверса
    void Revers()
    {
        cout << "Реверс: " << endl;
        if (stackTop == nullptr)
            cout << "Стек пустой" << endl;
        else {
            node<T>* prev = nullptr;
            while (stackTop) {
                node<T>* link = stackTop;
                stackTop = stackTop->next;
                link->next = prev;
                prev = link;
            }
            stackTop = prev;
        }
        print();
    }

    // деструктор
    ~stack()
    {
        clean();
    }
};

void main()
{
    setlocale(LC_ALL, "ru");

    //инициализируем стек
    stack<int> list;

    //запаолняем стек
    list.pushFront(3);
    list.pushFront(2);
    list.pushFront(1);

    cout << "Началный стек:" << endl;
    list.print();

    //реверс сразу с выводом
    cout << "Итоговый стек:" << endl;
    list.Revers();
}