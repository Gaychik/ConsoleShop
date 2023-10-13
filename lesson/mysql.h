#pragma once
#include "Item.h"
#include "Client.h"
#include "Order.h"
#include <string>
void connection_to_db();
vector<Item> get_items(string);
bool insert_item(Item);
bool delete_item(int);
bool insert_client(Client );
Client* get_client(string ,string);
bool insert_order(Order);
Item get_item(int);
vector<Item>get_items_by_order(int);
bool update_item(vector<Item>);

