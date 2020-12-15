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

    //��������� ����� ����� � ����� ������
    void add(product new_prod)
    {
        products.push_back(new_prod);
    }

    //���������� ����� ��� ����� ���� ��� �� ������
    void sale_price() {
        cout << "������!" << endl;
        for_each(products.begin(), products.end(), [](product& defprod) {
            defprod.sale();
            defprod.output();
            cout << endl;
            defprod.endsale();
            });
    }

    //������ � �������� ����� ������
    void AllOutAttack() {
        cout << "\n" << "��� ������:" << endl;
        for (iter = products.begin(); iter != products.end(); iter++) {
            iter->output();
            cout << endl;
        }
    }

    //������� ��������� �������, ���� �� ����� ���������� �������� ������� ����� - ������� ������������, �� ��������� ��� ������� �����������
    //����� ������� ��� �� ������� ����������
    void search(product prod) {
        product prodtmp;
        cout << "����� ���� � 4 ������. . ." << endl;
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

    //��� ������� ������� �������, �� ������� ��������� - ���� ��� ������� � �������
    void delthis(product prod) {
        cout << "�������. . ." << endl;
        iter = find_if(products.begin(), products.end(), [&prod](product& defprod) {
            return prod.getName() == defprod.getName();
            });
        products.erase(iter);
    }

    //�������� �� ������� ������
    void check_void() {
        if (products.empty() == 1) {
            cout << "������ ����" << endl;
        }
        else {
            cout << "������ �� ����" << endl;
        }
    }

    //������ ������
    void rev() {
        cout << "������. . ." << endl;
        reverse(products.begin(), products.end());
    }

    //������� ���������� sort ��� ���������� ������� �� �����
    void name_s() {
        cout << "���������. . ." << endl;
        sort(products.begin(), products.end(), [](product& defprod1, product& defprod2) {
            return (defprod1.getName() < defprod2.getName());
        });
    }

    //����� ���������� max element ���� ����� ����� ������� �����
    void expen() {
        cout << "����� ������� �����:" << endl;
        iter = max_element(products.begin(), products.end(), [](product& defprod1, product defprod2) {
            return (defprod1.getPrice() < defprod2.getPrice());
        });
        iter->output();
    }
    //��������� ������ �������
    void reorg() {
        cout << "������ ������. . ." << endl;
        random_shuffle(products.begin(), products.end());

    }

    //������� ���������� �������, ������� ������ 100
    int count_exp() {
        int count = count_if(products.begin(), products.end(), [](product& defprod) {
            return defprod.getCount() > 100;
            });
        return count;
    }

    //������� ������
    void cle() {
        cout << "������. . ." << endl;
        products.clear();
    }
};
