#include "MenuFunctions.h"
#include "Customer.h"
#include "Employee.h"
#include "Sale.h"
#include "Purchase.h"
#include "Supplier.h"
#include "Medicine.h"

#include "requirements.h"
#include "dbConfig.h"




void mainMenu() {
    int choice;
    while (true) {
        system("cls");
        cout << "*************************************************" << endl;
        cout << "         Pharmacy MANAGEMENT SYSTEM" << endl;
        cout << "*************************************************" << endl;
        cout << "   1. Medicines" << endl;
        cout << "   2. Suppliers" << endl;
        cout << "   3. Purchases" << endl;
        cout << "   4. Employees" << endl;
        cout << "   5. Customers" << endl;
        cout << "   6. Sales" << endl;
        cout << "   7. Exit" << endl << endl << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                medicineMenu();
                break;
            case 2:
                system("cls");
                supMenu();
                break;
            case 3:
                system("cls");
                purMenu();
                break;
            case 4:
                system("cls");
                empMenu();
                break;
            case 5:
                system("cls");
                cusMenu();
                break;
            case 6:
                system("cls");
                salMenu();
                break;
            case 7:
                exit(1);
            default:
                system("cls");
                cout << "Wrong Input" << endl << endl;
                break;
        }
    }
}

void medicineMenu() {
    int choice;
    Medicine m;
    while (true) {
        system("cls");
        cout << "*************************************************" << endl;
        cout << "                  PHARMACY MENU" << endl;
        cout << "*************************************************" << endl;
        cout << "   1. Add" << endl;
        cout << "   2. Update Price" << endl;
        cout << "   3. Search" << endl;
        cout << "   4. Update Status" << endl;
        cout << "   5. Display All" << endl;
        cout << "   6. Return to Main Menu" << endl << endl << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                m.addMedicine();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 2:
                m.updatePrice();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 3:
                m.search();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 4:
                m.update();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 5:
                m.displayMedicine();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 6:
                return;
                break;
            default:
                cout << "Wrong Input. Press any key to go back...";
                getch();
                break;
        }
    }
}

void supMenu() {
    int choice;
	Supplier s;
    while (true) {
        system("cls");
        cout << "*************************************************" << endl;
        cout << "                SUPPLIER MENU" << endl;
        cout << "*************************************************" << endl;
        cout << "   1. Add" << endl;
        cout << "   2. Remove" << endl;
        cout << "   3. Search" << endl;
        cout << "   4. Return to Main Menu" << endl << endl << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.addSupplier();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 2:
                s.removeSupplier();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 3:
                s.searchById();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 4:
                return;
                break;
            default:
                cout << "Wrong Input. Press any key to go back...";
                getch();
                break;
        }
    }
}

void purMenu() {
    int choice;
    Purchase p;
    while (true) {
        system("cls");
        cout << "*************************************************" << endl;
        cout << "                PURCHASES MENU" << endl;
        cout << "*************************************************" << endl;
        cout << "   1. New Order" << endl;
        cout << "   2. View All" << endl;
        cout << "   3. Cancel Order" << endl;
        cout << "   4. Received Order" << endl;
        cout << "   5. Return to Main Menu" << endl << endl << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.newOrder();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 2:
                p.view();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 3:
                p.markCancel();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 4:
                p.markReceived();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 5:
                return;
                break;
            default:
                cout << "Wrong Input. Press any key to go back...";
                getch();
                break;
        }
    }
}

void empMenu() {
    int choice;
    Employee e;
    while (true) {
        system("cls");
        cout << "*************************************************" << endl;
        cout << "                 EMPLOYEE MENU" << endl;
        cout << "*************************************************" << endl;
        cout << "   1. Add New Employee" << endl;
        cout << "   2. Search Employee" << endl;
        cout << "   3. Assign Manager Status" << endl;
        cout << "   4. View All Employees" << endl;
        cout << "   5. Update Salary" << endl;
        cout << "   6. Return to Main Menu" << endl << endl << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                e.addEmployee();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 2:
                e.searchEmployee();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 3:
                e.assignManagerStatus();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 4:
                e.display();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 5:
                e.updateSalary();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 6:
                return;
                break;
            default:
                cout << "Wrong Input. Press any key to go back...";
                getch();
                break;
        }
    }
}

void cusMenu() {
    int choice;
    Customer c;
    while (true) {
        system("cls");
        cout << "*************************************************" << endl;
        cout << "                 CUSTOMERS MENU" << endl;
        cout << "*************************************************" << endl;
        cout << "   1. Add New Customer" << endl;
        cout << "   2. Search Customer" << endl;
        cout << "   3. Return to Main Menu" << endl << endl << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                c.addCustomer();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 2:
                c.searchCustomer();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 3:
                return;
                break;
            default:
                cout << "Wrong Input. Press any key to go back...";
                getch();
                break;
        }
    }
}

void salMenu() {
    int choice;
    Sale sl;
    while (true) {
        system("cls");
        cout << "*************************************************" << endl;
        cout << "                 SALES MENU" << endl;
        cout << "*************************************************" << endl;
        cout << "   1. Add New Bill" << endl;
        cout << "   2. Total Sales Of The Year" << endl;
        cout << "   3. Return to Main Menu" << endl << endl << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                sl.addSale();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 2:
                sl.findTotalSales();
                cout<<"Press any key to go back...";
                getch();
                break;
            case 3:
                return;
                break;
            default:
                cout << "Wrong Input. Press any key to go back...";
                getch();
                break;
        }
    }
}

void pass() {
    int num = 0 ;
    cout << "Enter password : ";
    for(int i = 0; i < 4; i++) {
        num=num*10+(getch()-48);
        cout<<"*";
    }
    if(num == PASSWORD) {
        cout << endl << endl << "Correct Password" << endl << endl;
        cout << "Press any key...";
        getch();
    } else {
        cout << endl << endl << "Incorrect Password" << endl << endl;
        cout << "Press any key...";
        getch();
        exit(1);
    }
}

