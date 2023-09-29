#pragma once
#include <string>
using namespace std;
struct Client
{
	Client(string p_name, int p_age)
	{
		name = p_name;
		age = p_age;
	}
public:
	string name;
	int age;
};