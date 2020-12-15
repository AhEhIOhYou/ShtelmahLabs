#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

class z {
public:
    //та самая нужная строка
    string mainText = "";

    //в конструкторе вытягиваем строку из файла и закидываем её в ОДНУ строку
    z() {
        string lines, buf;
        ifstream file("source.txt");
        while (getline(file, buf)) {
            mainText += buf;
        }
        file.close();
    }

    //используем итератторы и репплейс чтоб заменять значения
    string zamena(string text, string it_rep, string ir_rep_here) {
        int pos;
        while ((pos = text.find(it_rep)) != -1)
            text.replace(pos, it_rep.length(), ir_rep_here);
        return text;
    }

    //проверка, что введеное значение - дейстивтельно слово, булевая
    bool check_for_trueword(string inw) {
        bool ch_st = true;
        char* w = new char[inw.length() + 1];
        strcpy(w, inw.c_str());
        for (int i = 0; i < inw.length(); i++) {
            if (isalpha(w[i]) == 0) {
                ch_st = false;
                break;
            }
        }
        return ch_st;
    }

    //функция кастомного разделителя текста на строки, чтоб применить к 5 заданию оставим разделитель пустым
    //каждая строка делиться по de и лежит в векторе строк
    vector<string> vector_strs_spl(string deftext, string de = " ") {
        vector<string> str;
        string end = de;
        int ite_beg = 0;
        for (int i = 0; i < deftext.size(); i++) {
            for (int j = 0; j < end.size(); j++) {
                if (deftext[i] == end[j]) {
                    string new_w = deftext.substr(ite_beg, i - ite_beg);
                    if (new_w.size() > 0)
                        str.push_back(new_w);
                    ite_beg = i + 1;
                }
            }
        }
        return str;
    }
    //считаем кол-во слов в каждой строке
    void z1() {
        //делим текст на строки по "<"
        vector<string> str = vector_strs_spl(mainText, "<");
        vector<vector<string>> strs;
        for (string line : str) {
            strs.push_back(vector_strs_spl(line));
        }
        //перебираем элементы вектора - строки и если слово подтвердиться в функции чека, то увеличиваем локальную длинну строки
        for (auto line : strs) {
            int lenght = 0;
            for (auto word : line) {
                if (check_for_trueword(word)) {
                    lenght++;
                }
            }
            cout << "Слов - " << lenght + 1 << endl;
            //и обнуляем длину по новой
        }
    }
    //убрать все точки
    void z2() {
        cout << "Убираем все точки. . ." << endl;
        //просто меняем точки на пустое место
        cout << zamena(mainText, ".", "") << endl;
    }
    //вывести номер самой длинной строки
    int z3() {
        int lenght_max = 0;
        int str_number = 0;
        vector<string> str = vector_strs_spl(mainText, "<");
        //перебираем строки и сравнивваем с макс длиной
        for (int i = 0; i < str.size(); i++) {
            if (str[i].length() > lenght_max) {
                lenght_max = str[i].length();
                str_number = i;
            }
        }
        cout << "Самая длинная строка = " << str_number + 1 << endl;
        return str_number;
    }
    //заменить самую длинную строку - пустотой
    void z4() {
        cout << "Удаляем самую длинну строку. . ." << endl;
        string need_line;
        int lenght_max = 0;
        int str_number = 0;
        vector<string> str = vector_strs_spl(mainText, "<");
        for (int i = 0; i < str.size(); i++) {
            //ищем как в пред макс длину и запоминаем строку
            if (str[i].length() > lenght_max) {
                lenght_max = str[i].length();
                str_number = i;
                need_line = str[i];
            }
        }
        cout << zamena(mainText, need_line, "") << endl;
    }
    //Вывести на печать первое предложение текста, учитывая, что оно заканчивается точкой
    void z5()
    {
        cout << "Первое предложение. . ." << endl;
        cout << vector_strs_spl(mainText, ".")[0] << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    z t;
    t.z1();
    t.z2();
    t.z3();
    t.z4();
    t.z5();
    system("pause");
    return 0;
}