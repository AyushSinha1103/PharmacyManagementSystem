#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>

class Purchase {
private:
    int orderId;       // Primary Key
    int medicineId;    // FK ref (Medicine)
    int supplierId;    // FK ref (Suppliers)
    int quantity;
    char received;      // Check(T or C or F) default (F)
    int inv;

public:
    void newOrder();
    void view();
    void markCancel();
    void markReceived();
};

#endif // PURCHASE_H

