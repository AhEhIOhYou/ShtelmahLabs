#pragma once
#include <vector>
#include "product.h"
#include <algorithm>
using namespace std;

class products_list
{
private:
    vector<product> products;
    vector<product>::iterator iter;
public:

    //добавляем новый товар в конец списка
    void add(product new_prod)
    {
        products.push_back(new_prod);
    }

    //используем форич для вывод всех цен по скидке
    void sale_price() {
        cout << "Скидки!" << endl;
        for_each(products.begin(), products.end(), [](product& defprod) {
            defprod.sale();
            defprod.output();
            cout << endl;
            defprod.endsale();
            });
    }

    //выводи в принципе всего списка
    void AllOutAttack() {
        cout << "\n" << "Все товары:" << endl;
        for (iter = products.begin(); iter != products.end(); iter++) {
            iter->output();
            cout << endl;
        }
    }

    //функция принимает продукт, если во время распродажи исходный продукт будет - горячим предложением, то выведется все горячие предложения
    //иначе выведет все НЕ горячие предложени
    void search(product prod) {
        product prodtmp;
        cout << "Поиск ближ к 4 товару. . ." << endl;
        prod.sale();
        for (iter = products.begin(); iter != products.end(); iter++) {
            iter->sale();
            if (iter->hot() == prod.hot()) {
                iter->output();
                cout << endl;
            }
            iter->endsale();
        }
        cout << "-------------" << endl;
    }

    //эта функция удаляет продукт, на который ссылаются - ищет его позицию и удаляет
    void delthis(product prod) {
        cout << "Удаляем. . ." << endl;
        iter = find_if(products.begin(), products.end(), [&prod](product& defprod) {
            return prod.getName() == defprod.getName();
            });
        products.erase(iter);
    }

    //проверка на пустоту списка
    void check_void() {
        if (products.empty() == 1) {
            cout << "Список пуст" << endl;
        }
        else {
            cout << "Список не пуст" << endl;
        }
    }

    //реверс списка
    void rev() {
        cout << "Реверс. . ." << endl;
        reverse(products.begin(), products.end());
    }

    //функция использует sort для сортировки товаров по имени
    void name_s() {
        cout << "Сортируем. . ." << endl;
        sort(products.begin(), products.end(), [](product& defprod1, product& defprod2) {
            return (defprod1.getName() < defprod2.getName());
        });
    }

    //здесь используем max element чтоб найти самый дорогой товар
    void expen() {
        cout << "Самый дорогой товар:" << endl;
        iter = max_element(products.begin(), products.end(), [](product& defprod1, product defprod2) {
            return (defprod1.getPrice() < defprod2.getPrice());
        });
        iter->output();
    }
    //перемешка спсика товаров
    void reorg() {
        cout << "Мешаем товары. . ." << endl;
        random_shuffle(products.begin(), products.end());

    }

    //подсчет количество товаров, которых больше 100
    int count_exp() {
        int count = count_if(products.begin(), products.end(), [](product& defprod) {
            return defprod.getCount() > 100;
            });
        return count;
    }

    //очистка списка
    void cle() {
        cout << "Чистим. . ." << endl;
        products.clear();
    }
};
