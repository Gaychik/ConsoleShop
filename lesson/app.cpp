#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "mysql.h"
#include <windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	SetConsoleOutputCP(CP_UTF8);
	connection_to_db();
	auto items = get_items("items");
	cout << "����� �� ������ ������ �����?" << endl;
	int n = 0;
	for (auto item : items)
	{
		cout <<n+1<<")" << item.name << "-" << item.balance << endl;
		n++;
	}
	//int choice = -1;
	//vector<string> order;
	//cin >> choice;
	//while (choice != 0)
	//{
	//	    items[choice-1].balance--;
	//		order.push_back(names[choice - 1]);
	//		cout << "����� ������!\n�������� �� �� � ������ ���-�� ���?" << endl;
	//		cin >> choice;
	//}
	//	ofstream of;
	//	of.open("orders.txt");
	//	i = 0;
	//	of << "����� �" << rand() % 100 << endl;
	//	while (i < order.size())
	//	{
	//		of << order[i] << endl;
	//		i++;
	//	}
	//	of.close();
	//	cout << "�� ��������!";*/
	
}

