#include <iostream>
#include <climits>
#include <map>
#include <sstream>
#include <vector>
#include "hashtable.h"
#include "binarysearchtree.h"
#include "binarynode.h"
#include "customer.h"
#include "action.h"
#include "movie.h"
#include "store.h"
#include <iostream>
#include <fstream>

using namespace std;

void readFile(string input) {

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
	while (getline(in,LinesInput))
	{
		numberOfLines++;
	}
	cout <<"Number of Lines " << numberOfLines << endl;
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
int main() {
	
	Store *tempStore;
	tempStore->loadCustomersFromFile("data4customers.txt");
	tempStore->loadMoviesFromFile("data4movies.txt");
	tempStore->loadMoviesFromFile("data4commands.txt");

	string data = "B";
	int id = 0124;
	Classics *movie = new Classics(10, "Michael Boubla", "Fuck me up", 2018,
		6, "Deeksha", "Hossam", "D");
	create(data, id, movie, tempStore);

	system("Pause");
	return 1;
}
