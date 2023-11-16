#ifndef Furniture_H
#define Furniture_H
#include<iostream>
#include <fstream>
#include <string>

using namespace std;

class furniture {
protected:
    string size;
    int quantity;
    string place;

public:
    furniture(string size = "Null", int quantity = 0, string place = "Null") {
        this->size = size;
        this->quantity = quantity;
        this->place = place;
    }

    string getSize() {
        return size;
    }

    int getQuantity() {
        return quantity;
    }

    string getPlace() {
        return place;
    }

    void setSize(string size) {
        this->size = size;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    void setPlace(string place) {
        this->place = place;
    }
    void saveData() {
        ofstream file("furniture.txt", ios::app);
        if (file.is_open()) {
            file << "Size: " << getSize() << endl;
            file << "Quantity: " << getQuantity() << endl;
            file << "Place: " << getPlace() << endl;
            file.close();
            cout << "Data saved successfully." << endl;
        } else {
            cout << "Unable to open the file." << endl;
        }
    }

    void removeData() {
        ofstream file("furniture.txt");
        if (file.is_open()) {
            file.close();
            cout << "Data removed successfully." << endl;
        } else {
            cout << "Unable to open the file." << endl;
        }
    }
};

class table : public furniture {
private:
    int seats;

public:
    table(int seats = 0) : furniture() {
        this->seats = seats;
    }

    int getSeats() {
        return seats;
    }

    void setSeats(int seats) {
        this->seats = seats;
    }

    void displayInfo() {
        cout << "THE CHARACTERISTICS OF TABLES ARE:\n";
        cout << "Size: " << getSize() << endl;
        cout << "Quantity: " << getQuantity() << endl;
        cout << "Place: " << getPlace() << endl;
    }
};

class chair : public furniture {
private:
    string type;

public:
    chair(string type = "Null") : furniture() {
        this->type = type;
    }

    string getType() {
        return type;
    }

    void setType(string type) {
        this->type = type;
    }

    void displayInfo() {
        cout << "THE CHARACTERISTICS OF CHAIRS ARE:\n";
        cout << "Size: " << getSize() << endl;
        cout << "Quantity: " << getQuantity() << endl;
        cout << "Place: " << getPlace() << endl;
        cout << "Type: " << type << endl;
    }
};
#endif 
