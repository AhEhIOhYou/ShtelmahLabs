/*
 Дан вектор V. Определить количество повторений каждого числа в векторе V и
 вывести все различные элементы вектора V вместе с количеством их повторений(в порядке увеличения числа в векторе)*/

#include <iostream>
#include <Windows.h>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <map>

using namespace std;
int main()
{
    srand(time(NULL));

    //формируем уникальный случайный вектор, и сразу выводим его содержимое
    vector<int> defaultVector(20);
    cout << "Vector: ";
;    for (int i = 0; i < 20; i++) {
        defaultVector[i] = rand() % 9;
        cout << defaultVector[i] << ", ";
    }
    cout << endl;

    //Множества set содержат только уникальные элементы из нашего вектора, по нему будем выводить ключи карты
    set<int> uniqueSet(defaultVector.begin(), defaultVector.end());
    //Карта для заполнения
    map<int, int> outMap;

    cout << "After:" << endl;

    for (auto vecItem : uniqueSet)
    {
        //подсчет повторений определенного числа, это будет значением в карте
        int rep;
        rep = count(defaultVector.begin(), defaultVector.end(), vecItem);

        //заполняем мапу
        outMap.insert(pair<int, int>(vecItem, rep));
    }

    // выводим карту
    map <int, int> ::iterator it = outMap.begin();
    for (int i = 0; it != outMap.end(); it++, i++) {
        cout << "\"" << it->first << "\" repeats " << it->second << " times " << endl;
    }
    system("pause");
    return 0;
}