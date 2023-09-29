#pragma once
#include "Item.h"
#include <vector>
void connection_to_db();
vector<Item> get_items(string table);
void insert_item(Item item);
void delete_item(int id);