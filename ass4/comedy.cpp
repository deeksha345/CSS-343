#include<string>
#include "comedy.h"
using namespace std;

// constructor that takes in arguments for all data members of movie 
// that are used to instantiate a comedy movie 
Comedy::Comedy(int stock, string director, string title, int yearOfRelease,
	string movieCode)
{
	movieType = "F";
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->yearOfRelease = yearOfRelease;
	this->movieCode = movieCode;
}

// overloaded operator==. Items are sorted by title and then year of release 
bool Comedy::operator==(Movie& other)
{
	Comedy temp = static_cast<Comedy&>(other);

	if (title == temp.title)
	{
		if (yearOfRelease == temp.yearOfRelease)
			return true;
		return false;
	}
	return false;
}

// overloaded operator<. Items are sorted by title and then year of release 
bool Comedy::operator<(Movie& other)
{
	Comedy temp = static_cast<Comedy&>(other);

	if (title == temp.title)
	{
		if (yearOfRelease < temp.yearOfRelease)
			return true;
		return false;
	}
	else if (title < temp.title)
		return true;
	return false;
}

// overloaded operator>. Items are sorted by title and then year of release
bool Comedy::operator>(Movie& other)
{
	Comedy temp = static_cast<Comedy&>(other);

	if (title == temp.title)
	{
		if (yearOfRelease < temp.yearOfRelease)
			return true;
		return false;
	}
	else if (title > temp.title)
		return true;
	return false;
}