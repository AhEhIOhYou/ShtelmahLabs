template <typename MyNodeType> class List;
template <typename MyNodeType> class IteratorForList;

template <typename MyNodeType>
class Node {
public:
    //методы - конструктор и доставка данных
    Node(const MyNodeType&);
    MyNodeType getData() const;

private:
    // значение звена
    MyNodeType data;
    //указатель на следующий узел в списке
    Node <MyNodeType>* nextPtr;

    //классы списка и итератор для списка делаем дружественными, для свободного доступа
    friend class List<MyNodeType>;
    friend class IteratorForList<MyNodeType>;

};

template <typename MyNodeType>
//дефолтный конструктор  
Node <MyNodeType>::Node(const MyNodeType& info) : data(info), nextPtr(0) { }

template <typename MyNodeType>
//получение значения
MyNodeType Node <MyNodeType>::getData() const {
    return data;
}