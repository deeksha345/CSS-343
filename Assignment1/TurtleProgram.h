/*
Author: Deeksha Sharma 
Date: 01/09/2017
Class description:
5. == and !=
7. + +=
8. * *=
9. getLength
10. setIndex / getIndex
*/

#ifndef TURTLEPROGRAM_H
#define TURTLEPROGRAM_H

#include<iostream>
#include<string>

using namespace std;

class TurtleProgram
{
	friend ostream &operator<<(ostream &, const TurtleProgram &);

public:
	TurtleProgram( ); // default constructor
	TurtleProgram(string a, string b); //2 parameter constructor 
	TurtleProgram(const TurtleProgram &); // copy constructor
	~TurtleProgram(); // destructor
	
	//overload operator functions 
	TurtleProgram &operator=(const TurtleProgram &);
	bool operator==(const TurtleProgram &) const;
	bool operator!=(const TurtleProgram &) const;
	TurtleProgram& operator+(const TurtleProgram &) const;
	TurtleProgram &operator+=(const TurtleProgram &); 
	TurtleProgram operator*(const int); 
	TurtleProgram &operator*=(const int); 

	//get and set methods 
	int getLength() const;
	string& getIndex(const int) const;
	void setIndex(const string, int);

	string* createArray(int) const;

private:
	TurtleProgram(string* tempArray, int); //
	string* turtleInstructions = NULL;
	int numElements;
	int MIN_SIZE = 2; 
};

#endif 
