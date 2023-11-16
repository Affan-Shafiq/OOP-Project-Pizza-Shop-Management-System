#ifndef Pizza_H
#define Pizza_H
#include<iostream>
#include<conio.h>
using namespace std;

class pizza {
	protected:
	    string size;
	    int cheeseToppings;
	    int pepperoniToppings;
	    int chickenToppings;
	    string flavour;
	public:
	    pizza(string size = "Null", int cheeseToppings = 0, int pepperoniToppings = 0, int chickenToppings = 0, string flavour = "Null") {
	        this->size = size;
	        this->cheeseToppings = cheeseToppings;
	        this->pepperoniToppings = pepperoniToppings;
	        this->chickenToppings = chickenToppings;
	        this->flavour = flavour;
	    }
	    string getSize() {
	        return size;
	    }
	    int getCheeseToppings() {
	        return cheeseToppings;
	    }
	    int getPepperoniToppings() {
	        return pepperoniToppings;
	    }
	    int getChickenToppings() {
	        return chickenToppings;
	    }
	    string getFlavour() {
	        return flavour;
	    }
	    void setSize(string size) {
	        this->size = size;
	    }
	    void setCheeseToppings(int cheeseToppings) {
	        this->cheeseToppings = cheeseToppings;
	    }
	    void setPepperoniToppings(int pepperoniToppings) {
	        this->pepperoniToppings = pepperoniToppings;
	    }
	    void setChickenToppings(int chickenToppings) {
	        this->chickenToppings = chickenToppings;
	    }
	    void setFlavour(string flavour) {
	        this->flavour = flavour;
	    }
	    void displayPizza() {
	        cout << "THE PIZZA YOU HAVE ORDERED HAS THE FOLLOWING CHARACTERISTICS:\n";
	        cout << "Flavour: " << flavour << endl;
	        cout << "Size: " << size << endl;
	        cout << "No of cheese toppings: " << cheeseToppings << endl;
	        cout << "No of pepperoni toppings: " << pepperoniToppings << endl;
	        cout << "No of chicken toppings: " << chickenToppings << endl;
	    }
	    int calcCost() {
	        int totalCost = 0;
	        if (flavour == "bbq" || flavour == "chickentiqqa" || flavour == "grillchicken") {
	            if (size == "small") {
	            totalCost = 10 + (2 * cheeseToppings) + (2 * pepperoniToppings) + (2 * chickenToppings);
		        }
				else if (size == "medium") {
		        	totalCost = 15 + (2 * cheeseToppings) + (2 * pepperoniToppings) + (2 * chickenToppings);
		        }
				else if (size == "large") {
		            totalCost = 20 + (2 * cheeseToppings) + (2 * pepperoniToppings) + (2 * chickenToppings);
		        }
				else {
		            totalCost = 25 + (2 * cheeseToppings) + (2 * pepperoniToppings) + (2 * chickenToppings);
		            }
		        }
			else {
	            if (size == "small") {
	                totalCost = 6 + (2 * cheeseToppings) + (2 * pepperoniToppings);
	            } else if (size == "medium") {
	                totalCost = 12 + (2 * cheeseToppings) + (2 * pepperoniToppings);
	            } else if (size == "large") {
	                totalCost = 16 + (2 * cheeseToppings) + (2 * pepperoniToppings);
	            } else {
	                totalCost = 20 + (2 * cheeseToppings) + (2 * pepperoniToppings);
	            }
	        }
	        return totalCost;
	    }
	    void placeOrder() {
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
	
	    // Save the pizza order to a file
	    ofstream outfile("pizza.txt",ios::app);
	    if (outfile) {
	        outfile << "Pizza Details\n";
	        outfile << "----------------\n";
	        outfile << "Size: " << size << endl;
	        outfile << "Flavour: " << flavour << endl;
	        outfile << "Cheese Toppings: " << cheeseToppings << endl;
	        outfile << "Pepperoni Toppings: " << pepperoniToppings << endl;
	        outfile << "Chicken Toppings: " << chickenToppings << endl;
	        outfile.close();
	        cout << "Pizza order placed successfully.\n";
	    }
		else {
	        cout << "Error placing pizza order.\n";
	    }
	}
	void cancelOrder() {
	    if (remove("pizza.txt") == 0) {
	        cout << "Pizza order canceled successfully.\n";
	    } else {
	        cout << "Error canceling pizza order.\n";
	    }
	}
	void retrieveOrder() {
    	ifstream infile("pizza.txt");
    	if (infile) {
        	string line;
        	cout << "Retrieved Pizza Order\n";
        	cout << "---------------------\n";
        	while (getline(infile, line)) {
            	cout << line << endl;
        	}
        	infile.close();
    	}	 
		else {
        	cout << "Error retrieving pizza order.\n";
    	}
	}

};
#endif 
