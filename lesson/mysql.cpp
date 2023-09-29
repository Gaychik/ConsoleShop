
#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <vector>
#include "Item.h"
#include "config.h"
#include "mysql.h"
using namespace std;
using namespace sql;
//for demonstration only. never save your password in the code!
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
        items.push_back(Item(result->getInt(1), result->getString(2).c_str(), result->getInt(3)));
    }
    return items;
}
void insert_item(Item item)
{
    pstmt = con->prepareStatement("INSERT INTO Items(name,balance) values(?,?)");
    pstmt->setString(1,item.name);
    pstmt->setInt(2, item.balance);
    pstmt->execute();
}
void delete_item(int id)
{
    pstmt = con->prepareStatement("Delete from Items where id=?");
    pstmt->setInt(1, id);
    pstmt->execute();
}



