#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    int id;                 // Primary Key
    string name;
    string addrLine1;
    string addrLine2;
    string city;
    string state;
    long long int phone;
    long int salary;
    string managerStatus; // Check(T or F) default F

public:
    void addEmployee();
    void searchEmployee();
    void assignManagerStatus();
    void display();
    void updateSalary();
};

#endif // EMPLOYEE_H

