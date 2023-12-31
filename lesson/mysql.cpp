
#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <vector>
#include "Item.h"
#include "Order.h"
#include "Client.h"
#include "config.h"
using namespace std;
using namespace sql;
Driver* driver;
Connection* con;
Statement* stmt;
PreparedStatement* pstmt;
ResultSet* result;
void connection_to_db()
{
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        con->setSchema(db_name);
        stmt = con->createStatement();
    }
    catch (SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
    }
}
vector<Item> get_items(string table)
{
    vector<Item> items;
    pstmt = con->prepareStatement("SELECT * FROM "+ table);
    result = pstmt->executeQuery();
    while (result->next())
    {
        items.push_back(Item(result->getString(2).c_str(), result->getInt(3), result->getInt(1)));
    }
    return items;
}
bool insert_item(Item item)
{
    pstmt = con->prepareStatement("INSERT INTO Items(name,balance) values(?,?)");
    pstmt->setString(1,item.name);
    pstmt->setInt(2, item.balance);
    //������������� 
    result = pstmt->executeQuery();
    cout << result->getInt(1) << endl;
    return true;
}
bool delete_item(int id)
{
    pstmt = con->prepareStatement("Delete from Items where id=?");
    pstmt->setInt(1, id);
    return pstmt->execute();
}
bool insert_order(Order order)
{
    pstmt = con->prepareStatement("INSERT INTO orders (client_id) values(?)");
    pstmt->setInt(1,order.client_id);
    result =pstmt->executeQuery();//�������� ���������� id, ����� ����������
    int order_id=result->getInt(1);
    
    for (auto item : order.items)
    {
        pstmt = con->prepareStatement("INSERT INTO orders_and_Items (order_id,item_id) values(?,?)");
        pstmt->setInt(1, order_id);
        pstmt->setInt(2, item.id);
        if (not pstmt->execute()) return false;
    }
    return true;
}
Item get_item(int item_id)
{
    pstmt = con->prepareStatement("Select * from items where id='"+to_string(item_id)+"' limit 1");
    result = pstmt->executeQuery();
    return Item(result->getString(2), result->getInt(3), result->getInt(1));
}
bool insert_client(Client client)
{
    pstmt = con->prepareStatement("INSERT INTO clients (name,age,password,login) values(?,?,?,?)");
    pstmt->setString(1, client.name);
    pstmt->setInt(2, client.age);
    pstmt->setString(3, client.pass);
    pstmt->setString(4, client.login);
    //����� ��������
    return pstmt->execute();
}
Client* get_client(string login,string password)
{
    Client* selected_client;
           pstmt = con->prepareStatement("Select * from clients where login=? and password=?");
           pstmt->setString(1, login);
           pstmt->setString(2, password);
    result=pstmt->executeQuery();
    if (not result->first()) return nullptr;
    selected_client = new Client(
        result->getString(2).c_str(),//���
        result->getInt(5),//�������
        result->getString(3).c_str(),//�����
        result->getString(4).c_str(),//������
        result->getInt(1),
        result->getString(6)//id
    );
        return selected_client;
}
vector<Item>get_items_by_order(int order_id)
{
    vector<Item> items;
    pstmt = con->prepareStatement("SELECT * FROM orders_and_items WHERE =" + to_string(order_id));
    result = pstmt->executeQuery();
    while (result->next())
        items.push_back(get_item(result->getInt(2)));
    return items;
}
bool update_item(vector<Item> items)
{
    pstmt = con->prepareStatement("UPDATE items SET balance=? WHERE name=?");
    bool result=true;
    for (auto item : items)
    {
        pstmt->setInt(1,item.balance);
        pstmt->setString(2, item.name);
        result=pstmt->execute();
        if (result == false)
        {
            cout << "Error when purchacing item!" << endl;
            return result;
        }
    }
    return result;
}



