#include<string>
#include "classic.h"
using namespace std;

// constructor that takes in arguments for all data members of movie 
// that are used to instantiate a classic movie  
Classics::Classics(int stock, string director, string title, int yearOfRelease,
	int monthOfRelease, string majorActorFirstName, string majorActorLastName,
	string movieCode) {
	this->movieType = movieType;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->yearOfRelease = yearOfRelease;
	this->movieCode = movieCode;
	this->majorActorFirstName = majorActorFirstName;
	this->majorActorLastName = majorActorLastName;
	this->monthOfRelease = monthOfRelease;
}

// overloaded operator==. Items are sorted by release date and then major actor 
bool Classics::operator==(Movie& other)
{
	Classics temp = static_cast<Classics&>(other);

	int releaseDate = monthOfRelease + yearOfRelease;
	int otherReleaseDate = temp.monthOfRelease + temp.yearOfRelease;
	string majorActor = majorActorFirstName + majorActorLastName;
	string otherMajorActor = temp.majorActorFirstName + 
		temp.majorActorLastName;

	if (releaseDate == otherReleaseDate)
	{
		if (majorActor == otherMajorActor)
			return true;
		return false;
	}
	return false;
}

// overloaded operator<. Items are sorted by release date and then major actor
bool Classics::operator<(Movie& other)
{
	Classics temp = static_cast<Classics&>(other);

	int releaseDate = monthOfRelease + yearOfRelease;
	int otherReleaseDate = temp.monthOfRelease + temp.yearOfRelease;
	string majorActor = majorActorFirstName + majorActorLastName;
	string otherMajorActor = temp.majorActorFirstName +
		temp.majorActorLastName;

	if (releaseDate == otherReleaseDate)
	{
		if (majorActor < otherMajorActor)
			return true;
		return false;
	}
	else if (releaseDate < otherReleaseDate)
		return true;
	return false;
}

// overloaded operator>. Items are sorted by release date and then major actor
bool Classics::operator>(Movie& other)
{
	Classics temp = static_cast<Classics&>(other);

	int releaseDate = monthOfRelease + yearOfRelease;
	int otherReleaseDate = temp.monthOfRelease + temp.yearOfRelease;
	string majorActor = majorActorFirstName + majorActorLastName;
	string otherMajorActor = temp.majorActorFirstName +
		temp.majorActorLastName;

	if (releaseDate == otherReleaseDate)
	{
		if (majorActor > otherMajorActor)
			return false;
		return true;
	}
	else if (releaseDate > otherReleaseDate)
		return true;
	return false;
}