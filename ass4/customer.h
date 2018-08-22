#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "movie.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Customer
{
public:
	Customer();    // default constructor 
	// constructor with parameters of string, string, and an int
	Customer(string, string, int);     
	~Customer();   // default desctructor 
	string getFirstName();  // returns first name of customer 
	string getLastName();  // returns last name of customer 
	int getId();           // returns ID of customer 
	void setFirstName(string);  // sets first name 
	void setLastName(string);   // sets last name 
	void setId(int);           // sets ID 
	void displayHistory();    // displays history of transactions for customer 
	void readFile(string input);  
	void setCustomerHistory(vector<string> input);  // sets customer history
	vector<string> getCustomerHistory();     // returns the customer history

private:
	string firstName; // stores customer's first name 
	string lastName;  // stores customer's last name 
	int id;          // stores customer's ID 
	vector<string> customerHistory;  // stores history of this customer 
};

#endif // CUSTOMER_H
