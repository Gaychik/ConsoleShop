#pragma once
#include <string>
struct Item
{
    Item(std::string _name, int _balance, int _id = 0);
public:
    int id;
    std::string name;
    int balance;
};
