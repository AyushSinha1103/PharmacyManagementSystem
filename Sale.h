#ifndef SALE_H
#define SALE_H


class Sale {
private:
    int invoiceId;     // Primary key
    int customerId;      // FK ref customer(id)
    int medicineId;    // FK ref Medicine(id)
    int quantity;
    int amount;

public:
    void addSale();
    void findTotalSales();
};

#endif // SALE_H

