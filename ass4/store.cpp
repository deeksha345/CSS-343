#include "store.h"
#include <string>


Store::Store() {

}
Store::~Store() {
customers.clear();
	
}
bool Store::addCustomer(string firstname, string lastname, int id) {
	if (customers.contain(id)) {
		return false;
	}
	else {
		Customer tempCustomer(firstname, lastname, id);
		customers.add(id, tempCustomer);
		return true;
	}
}
bool Store::removeCustomer(int id) {
	if (customers.contain(id)) {
		customers.remove(id);
		return true;
	}
	else {
		return false;
	}
}


void Store::displayCustomers() {
	vector<int> allKeys = customers.getAllKeys();
	for (int i = 0; i < allKeys.size(); i++) {
		cout << "Id: " << allKeys[i] << " Name: " << findCustomer(allKeys[i]) << endl;
	}
}

string Store::findCustomer(int id) {
	if (customers.contain(id)) {
		return customers.getValue(id).getFirstName() +" "+ customers.getValue(id).getLastName();
	}
	else {
		return "";
	}
}

bool Store::borrowMovie(Movie* movie, int id) {
	if (!movies.contain(movie->getMovieType())) {
		return false;
	}
	vector<Movie> allMoviesFromGenre = movies.getValue(movie->getMovieType());
	if (checkIfMovieIsAlreadyThere(movie->getTitle(), allMoviesFromGenre) == -1) {
		return false;
	}
	else {
		int index = checkIfMovieIsAlreadyThere(movie->getTitle(), allMoviesFromGenre);
		if (allMoviesFromGenre[index].getStock() >= 1) {
			allMoviesFromGenre[index].setStock(allMoviesFromGenre[index].getStock() - 1);
			movies.setValue(movie->getMovieType(), allMoviesFromGenre);
			return true;

		}
		else {
			cout << "We do not have anymore stock of this movie: " << movie->getTitle() << endl;
			return false;
		}
	}
}
void Store::activateHistoryCommand(string input) {

}
void Store::activateBorrowCommand(string input) {

}
void Store::activateReturnCommand(string input) {

}
void Store::activateInventoryCommand(string input) {

}
bool Store::returnMovie(Movie* movie, int id) {
	if (!movies.contain(movie->getMovieType())) {
		return false;
	}
	vector<Movie> allMoviesFromGenre = movies.getValue(movie->getMovieType());
	if (checkIfMovieIsAlreadyThere(movie->getTitle(), allMoviesFromGenre) == -1) {
		return false;
	}
	else {
		int index = checkIfMovieIsAlreadyThere(movie->getTitle(), allMoviesFromGenre);
			allMoviesFromGenre[index].setStock(allMoviesFromGenre[index].getStock() + 1);
			movies.setValue(movie->getMovieType(), allMoviesFromGenre);
			return true;

	}
}
void Store::displayCustomerHistory(int id) {
	printAllElementsFromVector(customersHistory.getValue(id));
}
void Store::displayInventory() {
	displayAllMoviesFromGenre("Comedy");
	displayAllMoviesFromGenre("Drama");
	displayAllMoviesFromGenre("Classics");

}
void Store::displayAllMoviesFromGenre(string input) {
	vector<Movie> movieVector = movies.getValue(input);
	if (input == "Comedy") {
		for (int i = 0; i < movieVector.size(); i++) {
			cout << "Genre: " << movieVector[i].getMovieType() << " Stock: " << movieVector[i].getStock() 
				<<" Director name" << movieVector[i].getDirector() << " Title: "
				<<movieVector[i].getTitle() <<" Major Actor: " << movieVector[i].getYearOfRelease() << endl;
		}
	}
	else if (input == "Drama") {
		for (int i = 0; i < movieVector.size(); i++) {
			cout << "Genre: " << movieVector[i].getMovieType() << " Stock: " << movieVector[i].getStock()
				<< " Director name" << movieVector[i].getDirector() << " Title: "
				<< movieVector[i].getTitle() << " Major Actor: " << movieVector[i].getYearOfRelease() << endl;
		}
	
	}
	else if (input == "Classics") {
		for (int i = 0; i < movieVector.size(); i++) {
			cout << "Genre: " << movieVector[i].getMovieType() << " Stock: " << movieVector[i].getStock()
				<< " Director name" << movieVector[i].getDirector() << " Title: "
				<< movieVector[i].getTitle() << " Major Actor: " << movieVector[i].getYearOfRelease() << endl;
		}

	}
}
int Store::checkIfMovieIsAlreadyThere(string movieTitle, vector<Movie> allMovies) {
	for (int i = 0; i < allMovies.size(); i++) {
		if (allMovies[i].getTitle() == movieTitle) {
			return i;
		}
	}
	return -1;
}
void Store::activatecommandUsingString(string input) {

	std::istringstream ss(input);
	std::string command;
	std::string token;
	int customerId;
	string movieFormat;
	string movieGenre;
	string movieTitle;
	string yearReleased;
	string directorName;
	string MajorActor;
	string ReleaseDate;
	int currentIndex = 0;
	int year;
	ss >> command;
	if (command == "H") {
		while (getline(ss,token))
		{

		}
	}
	else if (command == "I") {

	}
	else if (command == "B") {

	}
	else if (command == "R") {

	}
	else {
		cout << "Command " << command << " is invalid, Try either H,I,B,R" << endl;
	}

}
void Store::addMovieUsingString(string input) {
	
	std::istringstream ss(input);
	std::string genre;
	std::string token;
	int stock;
	string title;
	string directorName;
	string MajorActorReleaseDate;
	int currentIndex = 0;
	int year;
	std::getline(ss, genre, ',');
	Classics tempMovie;
	if (genre == "C") {
		while (getline(ss, token, ',')) {
			currentIndex++;
			if (currentIndex == 1) {
				stock = stoi(token);
			}
			else if (currentIndex == 2) {
				directorName = token;
			}
			else if (currentIndex == 3) {
				title = token;
			}
			else if (currentIndex == 4) {
				MajorActorReleaseDate = token;
				
			}
				
	}
		tempMovie.setTitle(title);
		tempMovie.setStock(stock);
		tempMovie.setDirector(directorName);
		tempMovie.setMajorActorName(MajorActorReleaseDate);
		if (movies.contain("Classics")) {
			vector<Movie> tempVector = movies.getValue("Classics");
			if (checkIfMovieIsAlreadyThere(title, movies.getValue("Classics")) != -1) {
				tempVector[checkIfMovieIsAlreadyThere(title, movies.getValue("Classics"))].setStock(
					tempVector[checkIfMovieIsAlreadyThere(title, movies.getValue("Classics"))].getStock() + stock);
					movies.setValue("Classics", tempVector);
			}
			else {
				tempVector.push_back(tempMovie);
				movies.setValue("Classics", tempVector);
			}
		}
		else {
			vector<Movie> tempVector;
			tempVector.push_back(tempMovie);
			movies.add("Classics", tempVector);

		}
	}
	else if (genre == "D") {
		while (getline(ss, token, ',')) {
			currentIndex++;
			if (currentIndex == 1) {
				stock = stoi(token);
			}
			else if (currentIndex == 2) {
				directorName = token;
			}
			else if (currentIndex == 3) {
				title = token;
			}
			else if (currentIndex == 4) {
				year = stoi(token);
			}
		}
		tempMovie.setTitle(title);
		tempMovie.setStock(stock);
		tempMovie.setDirector(directorName);
		tempMovie.setYearOfRelease(year);

		if (movies.contain("Drama")) {

			vector<Movie> tempVector = movies.getValue("Drama");
			if (checkIfMovieIsAlreadyThere(title, movies.getValue("Drama")) != -1) {
				tempVector[checkIfMovieIsAlreadyThere(title, movies.getValue("Drama"))].setStock(
					tempVector[checkIfMovieIsAlreadyThere(title, movies.getValue("Drama"))].getStock() + stock);
					movies.setValue("Drama", tempVector);

			}
			else {
				tempVector.push_back(tempMovie);
				movies.setValue("Drama", tempVector);
			}
		}
		else {
			vector<Movie> tempVector;
			tempVector.push_back(tempMovie);
			movies.add("Drama", tempVector);

		}

	}
	else if (genre == "F") {
		while (getline(ss, token, ',')) {
			currentIndex++;
			if (currentIndex == 1) {
				stock = stoi(token);
			}
			else if (currentIndex == 2) {
				directorName = token;
			}
			else if (currentIndex == 3) {
				title = token;
			}
			else if (currentIndex == 4) {
				year = stoi(token);
			}
		}
		tempMovie.setTitle(title);
		tempMovie.setStock(stock);
		tempMovie.setDirector(directorName);
		tempMovie.setYearOfRelease(year);

		if (movies.contain("Comedy")) {
			vector<Movie> tempVector = movies.getValue("Comedy");
			if (checkIfMovieIsAlreadyThere(title, movies.getValue("Comedy")) != -1) {
				tempVector[checkIfMovieIsAlreadyThere(title, movies.getValue("Comedy"))].setStock(
					tempVector[checkIfMovieIsAlreadyThere(title, movies.getValue("Comedy"))].getStock() + stock);
				movies.setValue("Comedy", tempVector);

			}
			else {
				tempVector.push_back(tempMovie);
				movies.setValue("Comedy", tempVector);
			}
		}
		else {
			vector<Movie> tempVector;
			tempVector.push_back(tempMovie);
			movies.add("Comedy", tempVector);

		}
	}
	else {
		cout << "Movie is incorrect type" << endl;
	}
}
vector<string> Store::dividestringBySpace(string input) {
	std::istringstream buffer(input);
	std::vector<std::string> ret;

	std::copy(std::istream_iterator<std::string>(buffer),
		std::istream_iterator<std::string>(),
		std::back_inserter(ret));
	return ret;

}
void Store::loadCommandsFromFile(string input) {

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
		activatecommandUsingString(LinesInput);
	}
	
	//close file
	fileDirectory.close();
}
void Store::loadMoviesFromFile(string input) {

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
	//create int numberOfEdgesTemp
	string genre;
	
	while (getline(in, LinesInput))
	{
		numberOfLines++;
		addMovieUsingString(LinesInput);

	}
	
	

	//close file
	fileDirectory.close();

}
void Store::loadCustomersFromFile(string input) {

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
	//create int numberOfEdgesTemp
	int idNumber;
	string firstName;
	string lastName;


	//loop through the rest of the edges in file
	for (int i = 0; i < numberOfLines; i++) {

		//store the first value in the documents inside of it
		fileDirectory >> idNumber;
		fileDirectory >> lastName;
		fileDirectory >> firstName;
		addCustomer(firstName, lastName, idNumber);

	}

	//close file
	fileDirectory.close();

}
void Store::printAllElementsFromVector(vector<string> input) {

	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << endl;
	}

}
void Store::addToHistory(int id,string input) {
	vector<string> tempVector = customersHistory.getValue(id);
	tempVector.push_back(input);
	customersHistory.setValue(id, tempVector);
	customers.getValue(id).setCustomerHistory(tempVector);
}
void Store::displayAllIds() {
	customers.printAllKeys();
}