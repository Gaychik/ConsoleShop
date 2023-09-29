#pragma once
#include <string>
using namespace std;
struct Item
{
    Item(int _id, string _name, int _balance)
    {
        id = _id;
        name = _name;
        balance = _balance;
    }
public:
    int id;
    string name;
    int balance;
};
