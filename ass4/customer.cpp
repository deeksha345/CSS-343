#include "customer.h"

// default constructor
Customer::Customer() {
	firstName = "";
	lastName = "";
	id = 0;
}
// constructor with parameters for the first and last name and the ID 
Customer::Customer(string firstNameInput, string lastNameInput, int idInput) {
	firstName = firstNameInput;
	lastName = lastNameInput;
	id = idInput;
}
// default desctructor 
Customer::~Customer() {}

string Customer::getFirstName() {
	return firstName;
}
string Customer::getLastName() {
	return lastName;
}
int Customer::getId() {
	return id;
}
void Customer::setFirstName(string value) {
	firstName = value;
}
void Customer::setLastName(string value) {
	lastName = value;
}
void Customer::setId(int value) {
	id = value;
}

// displays the customer history that is stored in the vector 
void Customer::displayHistory() {
	for (int i = 0; (unsigned)i < customerHistory.size(); i++) {
		cout << customerHistory[1] << endl;
	}
}
// used to set the customer history to the vector passed in 
void Customer::setCustomerHistory(vector<string> input) {
	customerHistory.clear();
	for (int i = 0; (unsigned)i < input.size(); i++) {
		customerHistory.push_back(input[i]);
	}
}
// returns the customer history 
vector<string> Customer::getCustomerHistory() {
	return customerHistory;
}

void Customer::readFile(string input) {

	//create ifstream fileDirectory
	std::ifstream fileDirectory;

	//open filename with it
	fileDirectory.open(input);

	//if it failed to open, return
	if (!fileDirectory.is_open()) {
		cout << "couldn't find file" << endl;
		return;
	}
	int numberOfLines = 0;
	ifstream in(input);
	string LinesInput;
	while (getline(in, LinesInput))
	{
		numberOfLines++;
	}
	cout << "Number of Lines " << numberOfLines << endl;
	//create int numberOfEdgesTemp
	int idNumber;
	string firstName;
	string lastName;

	//loop through the rest of the edges in file
	for (int i = 0; i < numberOfLines; i++) {
		//store the first value in the documents inside of it
		fileDirectory >> idNumber;
		cout << "Id " << idNumber << endl;
		fileDirectory >> lastName;
		cout << "Last Name " << lastName << endl;
		fileDirectory >> firstName;
		cout << "First Name " << firstName << endl;
	}

	//close file
	fileDirectory.close();
}

