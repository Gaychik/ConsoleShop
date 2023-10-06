#include <iostream>
#include "mysql.h"
void show_actions()
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
			//Добавить Item Controller
			break;
		case 2:
			//Добавить Item Controlle
			break;
		case 3:
			//Добавить Item Controlle
			break;
		default:
			cout << "Action incorrect. Repeat try" << endl;
			break;
		}
	}
}