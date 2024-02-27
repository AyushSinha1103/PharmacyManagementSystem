#include "Purchase.h"
#include "requirements.h"
#include "dbConfig.h"



void Purchase::newOrder()
{
    cout << "Enter the medicine Id: ";
    cin >> medicineId;
    cout << "Enter Supplier Id: ";
    cin >> supplierId;
    cout << "Enter the Quantity: ";
    cin >> quantity;
    stmt.str("");
    stmt << "INSERT INTO purchases (medicineId, supplierId, quantity, received) VALUES (" << medicineId << "," << supplierId << "," << quantity << ", 'F');";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << "New order added!!";
}

void Purchase::markReceived()
{
    cout << "Enter the order id for order received: ";
    cin >> orderId;
    stmt.str("");
    stmt << "UPDATE purchases SET received = 'T' WHERE orderId = " << orderId << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << "Received marked successfully";
}

void Purchase::markCancel()
{
    cout << "Enter the order id for order cancelled: ";
    cin >> orderId;
    stmt.str("");
    stmt << "UPDATE purchases SET received = 'C' WHERE orderId = " << orderId << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << "Cancelled marked successfully";
}

void Purchase::view()
{
    int c;
    cout << "Select an Option" << endl;
    cout << "1. View orders not Received" << endl;
    cout << "2. View orders Cancelled" << endl;
    cout << "3. View orders Received" << endl;
    cout << "Enter Your choice: ";
    cin >> c;
    if (c == 1)
        received = 'F';
    else if (c == 2)
        received = 'C';
    else if (c == 3)
        received = 'T';
    else
        return;
    stmt.str("");
    stmt << "SELECT * FROM purchases WHERE received = '" << received << "';";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if (c == 1)
        cout << endl << "Orders not received are" << endl;
    else if (c == 2)
        cout << endl << "Orders Cancelled are" << endl;
    else if (c == 3)
        cout << endl << "Orders received are" << endl;
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << endl;
        cout << "Order Id: " << row[0] << endl;
        cout << "Medicine Id: " << row[1] << endl;
        cout << "Supplier Id: " << row[2] << endl;
        cout << "Quantity: " << row[3] << endl;
        cout << endl << endl << endl;
    }
    cout << endl << endl << endl << endl << endl;
}

