#include<string>
#include "drama.h"
using namespace std;

// constructor with parameters for each data member 
Drama::Drama(int stock, string director, string title, int yearOfRelease,
	string movieCode)
{
	movieType = "D";
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->yearOfRelease = yearOfRelease;
	this->movieCode = movieCode;
}

// overloaded operator== method. Items are sorted by director and then title 
bool Drama::operator==(Movie &other)
{
	Drama temp = static_cast<Drama&>(other);

	if (director == temp.director)
	{
		if (title == temp.title)
			return true;
		return false;
	}
	return false;
}

// overloaded operator< method. Items are sorted by director and then title 
bool Drama::operator<(Movie &other)
{
	Drama temp = static_cast<Drama&>(other);

	if (director == temp.director)
	{
		if (title < temp.title)
			return true;
		return false;
	}
	else if (director < temp.director)
		return true;
	return false;
}

// overloaded operator> method. Items are sorted by director and then title 
bool Drama::operator>(Movie &other)
{
	Drama temp = static_cast<Drama&>(other);

	if (director == temp.director)
	{
		if (title > temp.title)
			return true;
		return false;
	}
	else if (director > temp.director)
		return true;
	return false;
}