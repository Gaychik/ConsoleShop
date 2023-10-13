#include "mysql.h"
#include "UserController.h"
#include <iostream>
#include "ItemController.cpp"
using namespace std;
void pay()
{
	connection_to_db();
	auto client_id = Authorize();
	cout << "What do you want to buy?" << endl;
	int choice = -1;
	auto order = Order(client_id);
	show_items();
	while (choice != 0)
	{
		cin >> choice;
		if (choice == 0) break;
		//вектор с товарами определяется в ItemController
		items[choice - 1].balance--;
		order.items.push_back(items[choice - 1]);
		cout << "Choice is selected.Add something else to your order or press zero!" << endl;
	}
	if (insert_order(order))
	{
		if (update_item(order.items))
			cout << "Our order is completed.Thank you for trusting us" << endl;
	}
	else cout << "Error when creating an order";
}