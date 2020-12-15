#pragma once
#include <iostream>
#include <string>
#include <ctime>

class product
{
private:
    std::string name;
    int p_count;
    int price;

public:
    product() {
        name = "default";
        p_count = rand() % 200;
        price = rand() % 10000;
    }
    //������ � �����
    product(std::string name) {
        this->name = name;
        p_count = rand() % 100 + 50;
        price = rand() % 9000 + 200;
    }
    //������ ����������
    void output() {
        std::cout << "�����: " << this->name << std::endl;
        std::cout << "����: " << this->price << std::endl;
        std::cout << "����������: " << this->p_count << std::endl;
        if (this->hot() == true) {
            std::cout << "������� �����������" << std::endl;
        }
    }
    //������ � ��������
    void sale() {
        int size_s = 2;
        this->price = this->price / size_s;
    }
    //�������� �������� �����������
    bool hot() {
        //���� ���-�� ������ 10 � ���� ������ 1000, �� �������
        if (p_count < 100 && price < 5000) {
            return true;
        }
        else
            return false;
    }
    //����� ������
    void endsale() {
        int size_s = 2;
        this->price = this->price * size_s;
    }
    //������ � �����
    std::string getName() {
        return name;
    }
    int getPrice() {
        return price;
    }
    int getCount() {
        return p_count;
    }
};
