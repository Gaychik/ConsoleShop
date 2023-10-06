#include <iostream>
#include <string>
#include "Client.h"
#include "mysql.h"
using namespace std;
Client* Register()
{
	string name, login, pass;
	int age;
	cout << "Enter  your name: " << endl;
	cin >> name;
	cout << "Enter  your login: " << endl;
	cin >> login;
	cout << "Enter  your password: " << endl;
	cin >> pass;
	cout << "Enter  your age: " << endl;
	cin >> age;
	Client* c = new Client(name, age, login, pass);//���������� ��������� "c" ������ ����� ���������� �������
	insert_client(*c);//�������� �������� �� ������ ��������� �.� ��� ��������� ��������� 
	c = get_client(login, pass);
	return c;//���������� ����� ������� ���������
}

int Authorize()
{
	string  login, pass;
	cout << "Enter  your login: " << endl;
	cin >> login;
	cout << "Enter  your password: " << endl;
	cin >> pass;
	auto client = get_client(login, pass);
	if (not client)
	{
		cout << "Do sign up now"<<endl;
		client=Register();
	}
	cout << "Sign in is succesfully completed!" << endl;
	return client->id;

}