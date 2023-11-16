#ifndef Customer_H
#define Customer_H
#include <iostream>

#include <fstream>
#include <string>

using namespace std;

class customer {
protected:
    string name;
    int orderNum;

public:
    customer(string name = "Null", int orderNum = 0) {
        this->name = name;
        this->orderNum = orderNum;
    }

    string getName() {
        return name;
    }

    int getOrderNum() {
        return orderNum;
    }

    void setName(string name) {
        this->name = name;
    }

    void setOrderNum(int orderNum) {
        this->orderNum = orderNum;
    }

    virtual void displayInfo() {
        cout << "Customer Data" << endl;
        cout << "Name: " << name << endl;
        cout << "Order Number: " << orderNum << endl;
    }
    void writeDataToFile() {
	    ofstream outfile("customer.txt");
	    if (outfile) {
	        outfile << "Customer Data\n";
	        outfile << "----------------\n";
	        outfile << "Name: " << name << endl;
	        outfile << "Order Number: " << orderNum << endl;
	        outfile.close();
	        cout << "Customer data written to file successfully.\n";
	    } else {
	        cout << "Error writing customer data to file.\n";
	    }
	}

	void readDataFromFile() {
	    ifstream infile("customer.txt");
	    if (infile) {
	        string line;
	        cout << "Customer Data\n";
	        cout << "----------------\n";
	        while (getline(infile, line)) {
	            cout << line << endl;
	        }
	        infile.close();
	    } else {
	        cout << "Error reading customer data from file.\n";
	    }
	}

    void placeOrderAsCustomer() {
	    string size, flavour;
	    int cheeseToppings, pepperoniToppings, chickenToppings;
	    cout << "Enter pizza details:\n";
	    cout << "Size: ";
	    cin >> size;
	    cout << "Flavour: ";
	    cin >> flavour;
	    cout << "Cheese Toppings: ";
	    cin >> cheeseToppings;
	    cout << "Pepperoni Toppings: ";
	    cin >> pepperoniToppings;
	    cout << "Chicken Toppings: ";
	    cin >> chickenToppings;
	    pizza p(size, cheeseToppings, pepperoniToppings, chickenToppings, flavour);
	
	    // Save the customer and pizza order to files
	    ofstream pizzaFile("pizza.txt",ios::app);
	    if (pizzaFile) {
	        pizzaFile << "Pizza Details\n";
	        pizzaFile << "----------------\n";
	        pizzaFile << "Size: " << p.getSize() << endl;
	        pizzaFile << "Flavour: " << p.getFlavour() << endl;
	        pizzaFile << "Cheese Toppings: " << p.getCheeseToppings() << endl;
	        pizzaFile << "Pepperoni Toppings: " << p.getPepperoniToppings() << endl;
	        pizzaFile << "Chicken Toppings: " << p.getChickenToppings() << endl;
	        pizzaFile.close();
	
	        cout << "Pizza order placed successfully.\n";
	    } else {
	        cout << "Error placing pizza order.\n";
	    }
	}
};

class dineInCustomer : public customer {
private:
    int tableNumber;
    int tax;

public:
    dineInCustomer(int tableNumber = 0, int tax = 0) {
        this->tableNumber = tableNumber;
        this->tax = tax;
    }

    int getTableNumber() {
        return tableNumber;
    }

    int getTax() {
        return tax;
    }

    void setTableNumber(int tableNumber) {
        this->tableNumber = tableNumber;
    }

    void calculateTax(int bill) {
        tax = bill * 0.025;
    }

    void displayInfo() override {
        cout << "Dine In Customer Data" << endl;
        cout << "Name: " << name << endl;
        cout << "Order Number: " << orderNum << endl;
        cout << "Table Number: " << tableNumber << endl;
        cout << "Tax: " << tax << endl;
    }
};

class onlineCustomer : public customer {
private:
    int contactNo;
    string address;
    string billType;

public:
    onlineCustomer(int contactNo = 0, string address = "Null", string billType = "Null") {
        this->contactNo = contactNo;
        this->address = address;
        this->billType = billType;
    }

    int getContactNo() {
        return contactNo;
    }

    string getAddress() {
        return address;
    }

    string getBillType() {
        return billType;
    }

    void setContactNo(int contactNo) {
        this->contactNo = contactNo;
    }

    void setAddress(string address) {
        this->address = address;
    }

    void setBillType(string billType) {
        this->billType = billType;
    }

    void displayInfo() override {
        cout << "Customer Data" << endl;
        cout << "Name: " << name << endl;
        cout << "Order Number: " << orderNum << endl;
        cout << "Contact No: " << contactNo << endl;
        cout << "Address: " << address << endl;
        cout << "Bill Type: " << billType << endl;
    }
};
#endif 
