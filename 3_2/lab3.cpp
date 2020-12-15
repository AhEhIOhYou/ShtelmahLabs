#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

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

string rev_words(string word)
{
    string temp_word = "";
    for (int i = word.length(); i > 0; i--)
        temp_word += word[i - 1];
    return word + temp_word;
}

int main()
{
    setlocale(LC_ALL, "ru");

    string str = "lo1llol k21ek f2 don1oonod pocemy poc1emy poce1my poce3my pocemy poce1my ds3d.";

    //делим строчку
    vector<string> v_str = vector_strs_spl(str, " ");
    //прогоняем каждое слово через функция переворота
    for (auto w : v_str) {
        cout << rev_words(w) << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}