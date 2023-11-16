#include<iostream>
#include<conio.h>
#include<string>

#include"pizza.h"
#include"employee.h"
#include"customer.h"
#include"furniture.h"

using namespace std;

int main() {
    // Prompt the user for the role (employee or customer)
    string role;
    cout << "Are you an employee or a customer? ";
    cin >> role;

    if (role == "employee") {
        // Prompt the employee for username and password
        string username;
int password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        // Authenticate the employee
        if (username == "a" && password == 123) {
            // Authentication successful
            manager m1;
            int choice;
            cout << "Authentication successful!\n";
            cout << "1. Add Worker\n";
            cout << "2. Remove Worker\n";
            cout << "3. Place Order\n";
            cout << "4. Retrieve Order\n";
            cout << "5. Cancel Order\n";
            cout << "6. Add Furniture\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    m1.addWorker();
                    break;
                case 2:
                    m1.removeWorker();
                    break;
                case 3:
                    pizza p1;
					p1.placeOrder();
					cout << p1.calcCost();
                    break;
                case 4:
                	pizza p1;
                	p1.retrieveOrder();
				case 5:
                    pizza p1;
					p1.cancelOrder();
                    break;
                case 6:
                	char option;
                	cout << "Enter 'c' for chairs and 't' for tables:";
                	cin >> option
                	if(option == 'c') {
                	string size, place;
                	int quantity;
					cout << "ENTER THE CHARACTERISTICS:\n";
			        cout << "Enter Size: " << size << endl;
			        cout << "Enter Quantity: " << quantity << endl;
			        cout << "Enter Place:" << place << endl;
					chair ch1;
					ch1.setSize(size);
					ch1.setQuantity(quantity);
					ch1.setPlace(place);
					ch1.saveData(); 
					}
					else if (option == 't'){
						string size, place;
	                	int quantity;
						cout << "ENTER THE CHARACTERISTICS:\n";
				        cout << "Enter Size: " << size << endl;
				        cout << "Enter Quantity: " << quantity << endl;
				        cout << "Enter Place:" << place << endl;
						table t1;	
						t1.setSize(size);
						t1.setQuantity(quantity);
						t1.setPlace(place);
						t1.saveData();
					} 
					else {
						cout << "Invalid Choice\n";
					}
                	break;
                default:
                    cout << "Invalid choice.\n";
            }
        } else {
            // Authentication failed
            cout << "Authentication failed!\n";
        }
    } else if (role == "customer") {
        // Place order as a 
        customer c1;
        c1.placeOrderAsCustomer();
    } else {
        cout << "Invalid role.\n";
    }

    return 0;
}
