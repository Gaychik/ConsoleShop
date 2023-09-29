#pragma once
#include "Item.h"
#include <vector>
struct Order
{
	Order(int p_client_id)
	{
		client_id = p_client_id;
	}
public:
	int item_id, client_id;
	vector<Item> items;
};