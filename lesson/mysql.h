#pragma once
#include "Item.h"
#include <vector>
#include "Client.h"
#include "Order.h"
void connection_to_db();
vector<Item> get_items(string table);
void insert_item(Item item);
void delete_item(int id);
void insert_client(Client client);
Client* get_client(string login, string password);
bool insert_order(Order order);
Item get_item(int item_id);
void insert_client(Client client);
Client* get_client(string login, string password);
vector<Item>get_items_by_order(int order_id);

