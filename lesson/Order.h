#pragma once
struct Order
{
	Order(int p_item_id, int p_client_id)
	{
		item_id = p_item_id;
		client_id = p_client_id;
	}
public:
	int item_id, client_id;
};