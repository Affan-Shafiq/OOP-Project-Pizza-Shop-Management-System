#ifndef Employee_H
#define Employee_H
#include <iostream>

#include <fstream>
#include <string>

using namespace std;

class employee {
	protected:
		string name;
		int employeeId;
		string address;
		int contactNo;
	public:
		employee(string name = "Null", int employeeId = 0, string address = "Null", int contactNo = 0) {
			this->name = name;
			this->employeeId = employeeId;
			this->address = address;
			this->contactNo = contactNo;
		}
		string getName() {
			return name;
		}
	int getEmployeeId() {
		return employeeId;
	}
	string getAddress() {
		return address;
	}
	int getContactNo() {
		return contactNo;
	}
	void setName(string name) {
		this->name = name;
	}
	void setEmployeeId(int employeeId) {
		this->employeeId = employeeId;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setContactNo(int contactNo) {
		this->contactNo = contactNo;
	}
	virtual void displayInfo() {
		cout << "Name of Employee:" << name << endl;
		cout << "ID:" << employeeId << endl;
		cout << "Contact No:" << contactNo << endl;
	}
};

class worker : public employee {
	protected:
		string areaOfExpertise;
		string placeOfWork;
	public:
		worker(string areaOfExpertise = "Null", string placeOfWork = "Null") {
			this->areaOfExpertise = areaOfExpertise;
			this->placeOfWork = placeOfWork;
		}
		string getAreaOfExpertise() {
			return areaOfExpertise;
		}
		string getPlaceOfWork() {
			return placeOfWork;
		}
		void setAreaOfExpertise(string areaOfExpertise) {
			this->areaOfExpertise = areaOfExpertise;
		}
		void setPlaceOfWork(string placeOfWork) {
			this->placeOfWork = placeOfWork;
		}	
		virtual void displayInfo() {
			cout << "Name of Worker:" << name << endl;
			cout << "ID:" << employeeId << endl;
			cout << "Contact No:" << contactNo << endl;
			cout << "Area Of Expertise:" << areaOfExpertise << endl;
			cout << "Place Of Work:" << placeOfWork << endl;
		}
};

class manager : public employee {
	protected:
		int yearsInOffice;
		worker* w1;
	public:
		manager(int yearsInOffice = 0) {
		this->yearsInOffice = yearsInOffice;
		w1 = new worker;
	}
	~manager() {
		delete w1;
	}
	int getYearsInOffice() {
		return yearsInOffice;
	}
	void setYearsInOffice(int yearsInOffice) {
		this->yearsInOffice = yearsInOffice;
	}
	void addWorker() {
    string areaOfExpertise, placeOfWork;
	cout << "Enter worker details:\n";
    cout << "Name: ";
    cin >> name;
    cout << "Employee ID: ";
    cin >> employeeId;
    cout << "Contact No: ";
    cin >> contactNo;
    cout << "Area of Expertise: ";
    cin >> areaOfExpertise;
    cout << "Place of Work: ";
    cin >> placeOfWork;
    w1->setName(name);
    w1->setEmployeeId(employeeId);
    w1->setContactNo(contactNo);
	w1->setAreaOfExpertise(areaOfExpertise);
	w1->setPlaceOfWork(placeOfWork);

    // Save the worker data to a file
    ofstream outfile("worker.txt",ios::app);
    if (outfile) {
        outfile << "Worker Details\n";
        outfile << "----------------\n";
        outfile << "Name: " << w1->getName() << endl;
        outfile << "Employee ID: " << w1->getEmployeeId() << endl;
        outfile << "Contact No: " << w1->getContactNo() << endl;
        outfile << "Area of Expertise: " << w1->getAreaOfExpertise() << endl;
        outfile << "Place of Work: " << w1->getPlaceOfWork() << endl;
        outfile.close();
        cout << "Worker details saved successfully.\n";
    } else {
        cout << "Error saving worker details to file.\n";
    }
    void readDataFromFile() {
	    ifstream infile("employee.txt");
	    if (infile) {
	        string line;
	        cout << "Employee Data\n";
	        cout << "----------------\n";
	        while (getline(infile, line)) {
	            cout << line << endl;
	        }
	        infile.close();
	    } else {
	        cout << "Error reading employee data from file.\n";
	    }
	}
	}
	void removeWorker() {
		if(remove("worker.txt") == 0) {
        	cout << "Worker details removed successfully.\n";
	    } 
		else {
        	cout << "Error removing worker details from file.\n";
    	}
	}
	virtual void displayInfo() {
	cout << "Name of Manager:" << name << endl;
	cout << "ID:" << employeeId << endl;
	cout << "Contact No:" << contactNo << endl;
	cout << "Years In Office:" << yearsInOffice << endl;
	}
};
#endif 
