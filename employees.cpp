#include "Employee.h"
#include "requirements.h"
#include "dbConfig.h"



void Employee::addEmployee()
{
    cout << "Enter Your Id for verification: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT managerStatus FROM employees WHERE id  = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) == NULL)
    {
        cout << "Employee Not Found!!" << endl << endl << endl;
        return;
    }
    else
    {
        managerStatus = (char *)row[0];
        cout<<managerStatus<<endl;
        if (managerStatus != "T")
        {
            cout << "You Do Not have Manager Rights!!!" << endl << endl;
            return;
        }
    }
    cout << "Enter The details of new employees:" << endl;
    cout << "Enter The name of the employee: ";
    cin >> name;
    cout << "Enter the Address (in 2 lines):" << endl;
    cin >> addrLine1;
    cin >> addrLine2;
    cout << "Enter City:";
    cin >> city;
    cout << "Enter State:";
    cin >> state;
    cout << "Enter phone no.:";
    cin >> phone;
    cout << "Enter the salary:";
    cin >> salary;
    stmt.str("");
	stmt << "INSERT INTO employees (name, addrLine1, addrLine2, city, state, phone, salary) VALUES ('" << name << "','" << addrLine1 << "','" << addrLine2 << "','" << city << "','" << state << "','" << phone << "','" << salary << "');";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << endl << "Employee Added Successfully!" << endl << endl << endl;
}

void Employee::assignManagerStatus()
{
    cout << "Enter Your Id for verification: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT managerStatus FROM employees WHERE id  = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) == NULL)
    {
        cout << "Employee Not Found!!" << endl << endl << endl;
        return;
    }
    else
    {
        managerStatus = (char *)row[0];
        if (managerStatus != "T")
        {
            cout << "You Do Not have Manager Rights!!!" << endl << endl;
            return;
        }
    }
    cout << "Enter the employee id to grant Manager status: ";
    cin >> id;
    stmt.str("");
    stmt << "UPDATE employees SET managerStatus = 'T' WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << endl << "Manager Status granted" << endl << endl;
}

void Employee::searchEmployee()
{
    cout << "Enter the id for searching an employee: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT * FROM employees WHERE id  = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Employees Details" << endl;
        cout << "Name: " << row[1] << endl;
        cout << "Address:" << endl << row[2] << endl << row[3] << endl;
        cout << "City: " << row[4] << endl;
        cout << "State: " << row[5] << endl;
        cout << "Contact no.: " << row[6] << endl;
        cout << "Salary: " << row[7] << endl << endl;
    }
    else
    {
        cout << "No Employee Found!!" << endl << endl;
    }
}

void Employee::display()
{
    int i = 0;
    query = "SELECT * FROM employees;";
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        do
        {
            cout << "Employees Details of Emp no." << ++i << endl;
            cout << "Name: " << row[1] << endl;
            cout << "Address:" << endl << row[2] << endl << row[3] << endl;
            cout << "City: " << row[4] << endl;
            cout << "State: " << row[5] << endl;
            cout << "Contact no.: " << row[6] << endl;
            cout << "Salary: " << row[7] << endl << endl;
        } while ((row = mysql_fetch_row(res_set)) != NULL);
    }
    else
    {
        cout << "Employees Not found!" << endl;
    }
}

void Employee::updateSalary()
{
    cout << "Enter the id to update the salary of an employee: ";
    cin >> id;
    cout << "Enter the updated salary: ";
    cin >> salary;
    stmt.str("");
    stmt << "UPDATE employees SET salary = " << salary << " WHERE id  = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << endl << "Salary update Successfully" << endl << endl;
}

