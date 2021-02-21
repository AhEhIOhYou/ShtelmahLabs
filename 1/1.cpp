#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	//���� �������� ������ V
	vector<int> V = { 5, 10, 15, 20, 25 , 50, 40, 30, 20, 10 };
	//����� ��� �� ��� �������, �� �������� - ������ � ������ ����� V
	vector<int> first(V.begin(), V.begin() + V.size() / 2);
	vector<int> second(V.begin() + V.size() / 2, V.end());

	//������ ������ ��� �����
	vector<int> out(3);
	//��������� ��� ��������
	vector<int>::iterator it, ls;

	//��������� ��� �������
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	//���� �������� �� ������ ��������������� ������������������ �� ���������, ��������� � ������ ������������������ 
	//[first.begin, first.end), �� ������������� �� ������ - [second.begin,second.end)
	ls = set_difference(first.begin(), first.end(), second.begin(), second.end(), out.begin());

	//��������������, ��� ������ �� �������
	reverse(out.begin(), out.end());

	//������� � ���
	ofstream file;
	file.open("out.txt");

	for (it = out.begin(); it < ls; ++it) {
		file << *it << ", ";
	}
	file.close();

	return 0;
}
