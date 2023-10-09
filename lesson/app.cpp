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
	connection_to_db();
	
	auto client_id = Authorize();
	cout << "What do you want to buy?" << endl;
	int choice = -1;

	auto order = Order(client_id);
	//нужно создать ItemController.h
	show_items()
	while (choice != 0)
	{
		cin >> choice;
		if (choice == 0) break;
		items[choice - 1].balance--;
		order.items.push_back(items[choice - 1]);
		cout << "Choice is selected.Add something else to your order or press zero!" << endl;
	}     
	if (insert_order(order)) cout << "Our order is completed.Thank you for trusting us" << endl;
	else cout << "Error when creating an order";

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

