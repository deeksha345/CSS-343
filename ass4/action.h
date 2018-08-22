#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <string>
#include "store.h"
using namespace std;

class Action
{
public:
	string data; // represents the type of action 
	Store* store; // pointer to the store 
	int id;  // represents the customer ID
	Movie* movie; // pointer to a movie 
	Action() {}; // default constructor 
	// constructor that takes in data and pointer to store
	Action(string data, Store* store) {
		this->data = data;
		this->store = store;
	};
	virtual void execute() = 0;  
	// create function used to create the commands 
	static Action* create(string data,Store* store, int id, Movie* movie);
};

// child class of Action 
class Borrow : public Action
{
public:
	// constructor for borrow command 
	Borrow(string data, Store* store, int id, Movie* movie) {
		this->data = data;
		this->store = store;
		this->id = id;
		this->movie = movie;
	}
	void execute() { store->borrowMovie(movie, id); }
};

// child class of Action 
class Return : public Action
{
public:
	int value; // holds value to be returned 
	// constructor for return command
	Return(string data, int value, Store* store, int id, Movie* movie) {
		this->data = data;
		this->value = value;
		this->store = store;
		this->id = id;
		this->movie = movie;
	}
	void execute() { store->returnMovie(movie, id); }
};

//child class of Action 
class History : public Action
{
public:
	// constructor for history command 
	History(string data, Store* store, int id) {
		this->data = data;
		this->store = store;
		this->id = id;
	}
	void execute() { store->displayCustomerHistory(id); }
};

// child class of Action 
class Inventory : public Action
{
public:
	// constructor for inventory command 
	Inventory(string data, Store* store) {
		this->data = data;
		this->store = store;
	}
	void execute() { store->displayInventory(); }
};

// implementation of create function that creates all the commands 
Action* Action::create(string data, Store* store, int id, Movie* movie) {
	if (type == "B") {
		return new Borrow(data, store, id, movie);
	}
	else if (type == "R") {
		return new Return(data, 1, store, id, movie);
	}
	else if (type == "I") {
		return new Inventory(data, store);
	}
	else if (type == "H") {
		return new History(data, store, id);
	}
	else {
		return nullptr;
	}
}

#endif // ACTION_H

