#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
using namespace std;

class Supplier {
private:
	int id;				//Primary Key
	string name;
	long long int phone;
	string addrLine1;
	string addrLine2;
	string city;
	string state;

public:
	void addSupplier();
	void removeSupplier();
	void searchById();
};

#endif // SUPPLIER_H
