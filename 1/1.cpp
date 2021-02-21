#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	//наши исходный вектор V
	vector<int> V = { 5, 10, 15, 20, 25 , 50, 40, 30, 20, 10 };
	//делим его на два вектора, по половине - первая и вторая часть V
	vector<int> first(V.begin(), V.begin() + V.size() / 2);
	vector<int> second(V.begin() + V.size() / 2, V.end());

	//вектор данных для файла
	vector<int> out(3);
	//итераторы для перебора
	vector<int>::iterator it, ls;

	//сортируем оба вектора
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	//этой функцией мы строим отсортированную последовательность из элементов, имеющихся в первой последовательности 
	//[first.begin, first.end), но отсутствующих во второй - [second.begin,second.end)
	ls = set_difference(first.begin(), first.end(), second.begin(), second.end(), out.begin());

	//переворачиваем, для вывода по заданию
	reverse(out.begin(), out.end());

	//выводим в тхт
	ofstream file;
	file.open("out.txt");

	for (it = out.begin(); it < ls; ++it) {
		file << *it << ", ";
	}
	file.close();

	return 0;
}
