#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "mysql.h"
#include <windows.h>
#include "Order.h"
#include "UserController.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	SetConsoleOutputCP(CP_UTF8);
	connection_to_db();
	auto items = get_items("items");
	auto client_id = Authorize();
	cout << "Какой вы хотите купить товар?" << endl;
	int n = 0;
	for (auto item : items)
	{
		cout <<n+1<<")" << item.name << "-" << item.balance << endl;
		n++;
	}
	int choice = -1;
	//Клиент регистрируется
	//Клиент авторизируется
	auto order = Order(client_id);

	while (choice != 0)
	{
		cin >> choice;
		if (choice == 0) break;
		items[choice - 1].balance--;
		order.items.push_back(items[choice - 1]);
		cout << "Choice is selected.Add something else to your order or press zero!" << endl;
	}
	insert_order(order);
	//{
	//	    
	//		order.push_back(names[choice - 1]);
	//		
	//		cin >> choice;
	//}
	//	ofstream of;
	//	of.open("orders.txt");
	//	i = 0;
	//	of << "Заказ №" << rand() % 100 << endl;
	//	while (i < order.size())
	//	{
	//		of << order[i] << endl;
	//		i++;
	//	}
	//	of.close();
	//	cout << "До свидания!";*/
	
}

