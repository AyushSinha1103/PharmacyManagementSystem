#include "Customer.h"
#include "requirements.h"
#include "dbConfig.h"



void Customer::addCustomer()
{
    cout << "Enter the name of the customer: ";
    cin >> name;
    cout << "Enter phone no.: ";
    cin >> phone;
    cout << "Enter address (in 2 lines)" << endl;
    cin >> addrLine1;
    cin >> addrLine2;
    cout << "Enter the city: ";
    cin >> city;
    cout << "Enter the state: ";
    cin >> state;

    stmt.str("");
    stmt << "INSERT INTO customers (name, addrLine1, addrLine2, city, state, phone) VALUES ('" << name << "','" << addrLine1 << "','" << addrLine2 << "','" << city << "','" << state << "'," << phone << ");";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    cout << "Customer Added successfully";
}

void Customer::searchCustomer()
{
    cout << "Enter customer id: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT * FROM customers WHERE id  = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Customer Details" << endl;
        cout << "Name: " << row[1] << endl;
        cout << "Address: " << endl << row[2] << endl << row[3] << endl;
        cout << "City: " << row[4] << endl;
        cout << "State: " << row[5] << endl;
        cout << "Contact no.: " << row[6] << endl;
    }
    else
    {
        cout << "No Customer Found!!" << endl << endl << endl;
    }
}

