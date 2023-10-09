#include "mysql.h"
#include <iostream>
#include <vector>

vector<Item> items;
void show_items()
{
	items = get_items("items");
	int n = 0;
	for (auto item : items)
	{
		cout << n + 1 << ")" << item.name << "-" << item.balance << endl;
		n++;
	}
}

void add_item()
{
	int balance;
	string name;
	cout << "Enter name for item: ";
	cin >> name;
	cout << "Enter first balance: ";
	cin >> balance;
	auto new_item = Item(name, balance);
	if (insert_item(new_item))
	{
		system("cls");
		show_items();
		items.push_back(new_item);
		cout << "Item is succesfully added" << endl;	
	}
	else cout << "Error" << endl;
}
void remove_item()
{
	int id_rem;
	cout << "Enter number of the item you want to delete: ";
	cin >> id_rem;
	if (delete_item(items[id_rem - 1].id))
	{
		system("cls");
		show_items();
		cout << "Item is succesfully removed";
	}
	else  cout << "Error";
}