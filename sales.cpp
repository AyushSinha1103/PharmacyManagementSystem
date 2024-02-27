#include "Sale.h"
#include "requirements.h"
#include "dbConfig.h"


void Sale::addSale()
{
    cout << "Enter Customer id: ";
    cin >> customerId;
    cout << "Enter the medicine id: ";
    cin >> medicineId;
    cout << "Enter the quantity: ";
    cin >> quantity;

    stmt.str("");
    stmt << "SELECT price * " << quantity << " FROM medicines WHERE id = " << medicineId << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "The bill amount: " << row[0] << endl << endl;
        amount = atoi(row[0]);
    }
    else
    {
        cout << "Invalid Book Id!" << endl;
        return;
    }

    stmt.str("");
    stmt << "INSERT INTO sales (customerId, medicineId, quantity, amount) VALUES (" << customerId << "," << medicineId << "," << quantity << "," << amount << ");";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    cout<<"order successful";
}

void Sale::findTotalSales()
{
    query = "SELECT SUM(amount) FROM sales;";
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Total sales: " << row[0] << endl << endl;
    }
}

