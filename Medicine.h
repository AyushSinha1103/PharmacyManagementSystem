#ifndef MEDICINE_H
#define MEDICINE_H

#include <string>
using namespace std;

class Medicine {
private:
    int id;            // Primary Key
    string name;
    string manufacturer;
    double price;
    int quantity;

public:
    void addMedicine();
    void updatePrice();
    void search();
    void update();
    void displayMedicine();
};

#endif // MEDICINE_H

