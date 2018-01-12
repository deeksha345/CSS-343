#include "TurtleProgram.h"
#include<iostream>
#include<string>

using namespace std;

//default constructor 
TurtleProgram::TurtleProgram( ) 
{
	turtleInstructions = createArray(MIN_SIZE);
	numElements = MIN_SIZE;
}

TurtleProgram::TurtleProgram(string inputA, string inputB)
{
	turtleInstructions = createArray(MIN_SIZE);
	numElements = MIN_SIZE;

	turtleInstructions[0] = inputA;
	turtleInstructions[1] = inputB;
}

//copy constructor 
TurtleProgram::TurtleProgram(const TurtleProgram& turtleToCopy)
{
	int length = turtleToCopy.getLength();
	numElements = length;
	turtleInstructions = new string[length];
	for (int i = 0; i < length; i++)
	{
		turtleInstructions[i] = turtleToCopy.turtleInstructions[i];
	}
}

TurtleProgram::TurtleProgram(string* tempArray, int length)
{
	numElements = length;
	turtleInstructions = tempArray;
	cout << "end of con" << endl;
}

TurtleProgram::~TurtleProgram()
{
	delete[] turtleInstructions;
	turtleInstructions = NULL;
}

string* TurtleProgram::createArray(int size) const
{
	//string* tempArray = new string[size];

	string* tempArray = new;
	tempArray->reserve(size);
	tempArray->resize(size);

	for (int i = 0; i < size; i++)
	{
		tempArray[i] = "";
	}
	cout << "end of createArray" << endl;
	return tempArray;
}

TurtleProgram& TurtleProgram::operator=(const TurtleProgram& turtleToCopy) 
{
	cout << "action 1" << endl;
	if (this == &turtleToCopy || turtleToCopy.turtleInstructions == NULL) 
	{
		cout << "action 2" << endl;
		return *this; 
	}
	
	cout << "action 3" << endl;
	numElements = turtleToCopy.getLength();
	cout << "action 4" << endl;
	for (int i = 0; i < turtleToCopy.getLength(); i++)
	{
		cout << "action in for loop " << i << endl;
		turtleInstructions[i] = turtleToCopy.turtleInstructions[i];
	}
	
	cout << "end of operator=" << endl;
	return *this;
}

ostream &operator<<(ostream &output, const TurtleProgram &turtle)
{ 
	output << "[ ";
	for (int i = 0; i < turtle.getLength(); i++)
	{
		if (turtle.turtleInstructions[i] == "") continue;
		output << turtle.turtleInstructions[i] << " ";
	}
	output << "]";
	return output;
}

int TurtleProgram::getLength() const
{ 
	return numElements;
}

string& TurtleProgram::getIndex(const int index) const
{
	return turtleInstructions[index];
}

void TurtleProgram::setIndex(const string newItem, int index)
{
	turtleInstructions[index] = newItem;
}

bool TurtleProgram::operator==(const TurtleProgram &turtleToCompare) const
{
	if (getLength() != turtleToCompare.getLength()) return false;

	for (int i = 0; i < turtleToCompare.getLength(); i++)
	{
		if (turtleInstructions[i] != turtleToCompare.turtleInstructions[i]) return false;
	}
	return true;
}

bool TurtleProgram::operator!=(const TurtleProgram &turtleToCompare) const
{
	return !(*this == turtleToCompare);
}

TurtleProgram& TurtleProgram::operator+(const TurtleProgram &turtleToAdd) const 
{
	cout << "action 1 in +" << endl;
	int length = getLength() + turtleToAdd.getLength();
	cout << "*this.getLength: " << getLength() << " turtleToAdd.getLength "
		<< turtleToAdd.getLength() << " length " << length << endl;
	cout << "action 2" << endl;
	TurtleProgram* tempTurtle = new TurtleProgram(createArray(length), length);
	
	cout << "action 3" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "action in for loop" << i << endl;
		if (i < getLength()) tempTurtle->turtleInstructions[i] = turtleInstructions[i];
		else tempTurtle->turtleInstructions[i] = turtleToAdd.turtleInstructions[i - getLength()];
	}

	cout << "end of +" << endl;
	return *tempTurtle;
}

TurtleProgram& TurtleProgram::operator+=(const TurtleProgram &turtleToAdd)
{
	*this = *this + turtleToAdd;
	return *this;
}

TurtleProgram TurtleProgram::operator*(const int multiplicationFactor) 
{
	int length = 2 * multiplicationFactor;
	TurtleProgram tempTurtle(createArray(length), length);

	for (int i = 0; i < length; i++)
	{
		if (i % 2 == 0) tempTurtle.turtleInstructions[i] = turtleInstructions[0];
		else tempTurtle.turtleInstructions[i] = turtleInstructions[1];
	}

	return tempTurtle;
}

TurtleProgram& TurtleProgram::operator*=(const int multiplicationFactor)
{
	*this = *this * multiplicationFactor;
	return *this; 
} 
