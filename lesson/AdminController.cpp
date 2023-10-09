#include <iostream>
#include "mysql.h"
#include "ItemController.h";
int show_actions()
{
	int choice = -1;
	while (choice!=0)
	{
		system("cls");
		cout << "1.Add the item" << endl;
		cout << "2. Remove the item" << endl;
		cout << "3. Show the items" << endl;
		cout << "0. Exit" << endl;
		cin >> choice;
		switch (choice)
		{	
		case 1:
			add_item();
			break;
		case 2:
			remove_item();
			break;
		case 3:
			show_items();
			break;
		default:
			cout << "Action incorrect. Repeat try" << endl;
			break;
		}
	}
	//Если работа с админ панелью завершена, возвращаем 0
	return choice;
}