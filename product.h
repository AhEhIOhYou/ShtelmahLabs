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
    //констр с парам
    product(std::string name) {
        this->name = name;
        p_count = rand() % 100 + 50;
        price = rand() % 9000 + 200;
    }
    //выводи информации
    void output() {
        std::cout << "Товар: " << this->name << std::endl;
        std::cout << "Цена: " << this->price << std::endl;
        std::cout << "Количество: " << this->p_count << std::endl;
        if (this->hot() == true) {
            std::cout << "Горячее предложение" << std::endl;
        }
    }
    //скидка в половину
    void sale() {
        int size_s = 2;
        this->price = this->price / size_s;
    }
    //проверка горячего предложения
    bool hot() {
        //если кол-во меньше 10 и цена меньше 1000, то горячее
        if (p_count < 100 && price < 5000) {
            return true;
        }
        else
            return false;
    }
    //конец скидки
    void endsale() {
        int size_s = 2;
        this->price = this->price * size_s;
    }
    //доступ к полям
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
