#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include "drama.h"
#include "classic.h"
#include "comedy.h"
#include "hashtable.h"
#include "customer.h"
#include "binarynode.h"
#include "binarysearchtree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

class Store
{
public:
	// default constructor
	Store();   
	// default desctructor 
	~Store(); 
	// adds customer with first and last name and ID passed in 
	// if customer isn't already added 
	bool addCustomer(string firstname, string lastname, int id); 
	// removes customer with the corresponding ID if found 
	bool removeCustomer(int id);
	// displays list of all customers
	void displayCustomers();  
	// displays list of all customer IDs
	void displayAllIds();    
	// finds customer with the corresponding ID
	string findCustomer(int id); 
	// borrows movie passed in
	bool borrowMovie(Movie* movie, int id); 
	// returns movie passed in
	bool returnMovie(Movie* movie, int id);  
	// displays the whole store inventory
	void displayInventory();   
	// displays the customers history with the corresponding ID 
	void displayCustomerHistory(int id); 
	// reads in a txt files and loads in a list of customers 
	void loadMoviesFromFile(string input);
	// reads in a txt files and loads in a list of movies 
	void loadCustomersFromFile(string input);
	// reads in a txt files and loads in a list of commands 
	void loadCommandsFromFile(string input);
	// adds to a customers history 
	void addToHistory(int id,string input); 
	// creates a movie with the string passed in 
	void addMovieUsingString(string input); 
	// ...
	void activatecommandUsingString(string input);
	// ...
	void activateHistoryCommand(string input);
	// ...
	void activateBorrowCommand(string input);
	// ...
	void activateReturnCommand(string input);
	// ...
	void activateInventoryCommand(string input);
	// displays all the movies in the store with the corresponding genre
	void displayAllMoviesFromGenre(string input);
	// ...
	vector<string> dividestringBySpace(string input);
	// checks if the movie with the title passed in is already in the 
	// vector allMovies 
	int checkIfMovieIsAlreadyThere(string movieTitle, vector<Movie> allMovies);
	
	
private:
	// is a hashtable of customers
	Hashtable <int, Customer> customers;
	// is a hashtables of customer history 
	Hashtable <int, vector<string>> customersHistory;
	// is a hashtable of movies 
	Hashtable <string, vector<Movie>> movies;
	// stores all the commands 
	vector<string> allCommands;
	// prints all the elements in the vector passed in 
	void printAllElementsFromVector(vector<string> input);
};

#endif // STORE_H


