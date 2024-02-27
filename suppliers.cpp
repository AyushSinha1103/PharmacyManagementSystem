#include "Supplier.h"
#include "requirements.h"
#include "dbConfig.h"


void Supplier::addSupplier()
{
    cout << "Enter the Supplier Name: ";
    cin >> name;
    cout << "Enter Phone no.: ";
    cin >> phone;
    cout << "Enter the address (in 2 lines): ";
    cin >> addrLine1;
    cin >> addrLine2;
    cout << "Enter City: ";
    cin >> city;
    cout << "Enter State: ";
    cin >> state;
    stmt.str("");
    stmt << "INSERT INTO suppliers(name, phone, addrLine1, addrLine2, city, state) VALUES('" << name << "'," << phone << ",'" << addrLine1 << "','" << addrLine2 << "','" << city << "','" << state << "');";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if (!(res_set))
        cout << endl
             << endl
             << "Supplier Record Inserted Successfully" << endl
             << endl
             << endl;
    else
        cout << endl
             << endl
             << "Entry ERROR !" << endl
             << "Contact Technical Team " << endl
             << endl
             << endl;
}

void Supplier::removeSupplier()
{
    cout << "Enter the supplier id to remove the Supplier: ";
    cin >> id;
    stmt.str("");
    stmt << "DELETE FROM suppliers WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << "Supplier Removed.";
}

void Supplier::searchById()
{
    cout << "Enter the supplier id to find the Supplier details: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT * FROM suppliers WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Details of Supplier Id: " << row[0] << endl;
        cout << "Name: " << row[1] << endl;
        cout << "Phone no.: " << row[2] << endl;
        cout << "Address Line 1: " << row[3] << endl;
        cout << "Address Line 2: " << row[4] << endl;
        cout << "City: " << row[5] << endl;
        cout << "State: " << row[6] << endl;
    }
    else
    {
        cout << "No Supplier Found!!";
    }
}

