#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    int id;                 // Primary Key
    string name;
    string addrLine1;
    string addrLine2;
    string city;
    string state;
    long long int phone;


public:
    void addCustomer();
    void searchCustomer();
};

#endif // CUSTOMER_H

