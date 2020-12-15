#include <iostream>
#include <Windows.h>
#include "List.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    //инициализируем списочек в типе инт с количеством элементов
    List<int> ListB(22);


    //инициалазируем итераторы для класса list - начала и конца
    List<int>::iterator listBegin = ListB.begin();
    List<int>::iterator listEnd = ListB.end();
    
    //пользуясь итераторами задаем не убывающие значения для списка от 10 до конца списка
    int i = 10;
    for (; listBegin != listEnd; ++listBegin) {
        (*listBegin) = i++;
    }
    
    cout << "\nЗаполненный список B:" << endl;;
    ListB.print();
    cout << endl;

    //реверсим список
    ListB.Revers();
    cout << endl;

    ListB.print();

    system("pause");
    return 0;
}