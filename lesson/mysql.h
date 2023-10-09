#pragma once
#include "Item.h"
#include <vector>
#include "Client.h"
#include "Order.h"
void connection_to_db();
vector<Item> get_items(string table);
bool insert_item(Item item);
bool delete_item(int id);
bool insert_client(Client client);
Client* get_client(string login, string password);
bool insert_order(Order order);
Item get_item(int item_id);
vector<Item>get_items_by_order(int order_id);

