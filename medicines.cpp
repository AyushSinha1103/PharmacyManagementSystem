#include "requirements.h"
#include "Medicine.h"
#include "dbConfig.h"





void Medicine::addMedicine()
{
    cout << "Enter the name of the medicine: ";
    cin >> name;
    cout << "Enter the manufacturer of the medicine: ";
    cin >> manufacturer;
    cout << "Enter the Price: ";
    cin >> price;
    cout << "Enter the Quantity Received: ";
    cin >> quantity;
    stmt.str("");
    stmt << "INSERT INTO medicines(name, manufacturer, price, quantity) VALUES('" << name << "','" << manufacturer << "'," << price << "," << quantity << ");";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if (!(res_set))
        cout << endl
        << endl
        << "Medicine Record Inserted Successfully" << endl
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

void Medicine::updatePrice()
{
    char choice;
    cout << "Enter the id of the medicine for update in price: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT name, price FROM medicines WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "The Name of the medicine is: " << row[0] << endl;
        cout << "The current price of the medicine is: " << row[1] << endl;
        cout << "Do you Want to Update the Price [y/n]: ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            cout << "Enter the new price: ";
            cin >> price;
            stmt.str("");
            stmt << "UPDATE medicines SET price = " << price << " WHERE id = " << id << ";";
            query = stmt.str();
    		q = query.c_str();
    		mysql_query(conn, q);
            res_set = mysql_store_result(conn);
            if (!(res_set))
                cout << endl
                << endl
                << "Medicine Price Updated Successfully" << endl
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
        else
        {
            cout << "No changes Made!!";
        }
    }
    else
    {
        cout << "No Medicine found!!!";
    }
}

void Medicine::search()
{
    cout << "Enter medicine id for details: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT * FROM medicines WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "The Details of Medicine Id " << row[0] << endl;
        cout << "The Name of the medicine is: " << row[1] << endl;
        cout << "The manufacturer of " << row[1] << " is " << row[2] << endl;
        cout << "The Price of the medicine is: " << row[3] << endl;
        cout << "The inventory count is " << row[4] << endl;
    }
    else
    {
        cout << "No record Found" << endl;
    }
}

void Medicine::update()
{
    int m_id[100], qty[100], i = 0, max;
    stmt.str("");
    stmt << "SELECT medicineId, quantity FROM purchases WHERE received = 'T' and inv IS NULL;";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    stmt.str("");
    stmt << "UPDATE purchases SET inv = 1 WHERE received = 'T' and inv IS NULL;";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        m_id[i] = atoi(row[0]);
        qty[i] = atoi(row[1]);
        i++;
    }
    max = i;
    for (i = 0; i < max; i++)
    {
        stmt.str("");
        stmt << "UPDATE medicines SET quantity = " << qty[i] << " WHERE id = " << m_id[i] << ";";
        query = stmt.str();
        q = query.c_str();
        mysql_query(conn, q);
    }
    cout << "The orders received have been updated.";
}

void Medicine::displayMedicine()
{
    int i = 0;
    query = "SELECT * FROM medicines;";
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Name for medicine " << ++i << " : " << row[1] << endl;
        cout << "Manufacturer: " << row[2] << endl;
        cout << "Price: " << row[3] << endl;
        cout << "Quantity: " << row[4] << endl;
        cout<<"---------------------------------------------------";
        cout << endl;
    }
}

