#include "mysql.h"
#include <iostream>
void show_items()
{
	auto items = get_items("items");
	int n = 0;
	for (auto item : items)
	{
		cout << n + 1 << ")" << item.name << "-" << item.balance << endl;
		n++;
	}
}

void add_item()
{
}

void remove_item()
{

}