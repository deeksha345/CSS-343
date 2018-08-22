#ifndef CLASSICS_H
#define CLASSICS_H

#include<vector>
#include "movie.h"

using namespace std;

class Classics : public Movie {
public: 
	// constructor that takes in arguments for all data members of movie 
	// that are used to instantiate a classic movie 
	Classics(int stock, string director, string title, int yearOfRelease,
		int monthOfRelease, string majorActorFirstName, 
		string majorActorLastName, string movieCode);

	bool operator==(Movie&); // compares 2 movies for equality 
	bool operator<(Movie&); // less than comparison of 2 movies
	bool operator>(Movie&); // greater than comparison of 2 movies
};

#endif // CLASSICS_H
