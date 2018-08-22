#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

using namespace std;

class Comedy : public Movie {
public:
	// constructor that takes in arguments for all data members of movie 
	// that are used to instantiate a comedy movie 
	Comedy(int stock, string director, string title, int yearOfRelease,
		string movieCode);
	
	bool operator>(Movie&); // greater than comparison of 2 movies
	bool operator<(Movie&); // less than comparison of 2 movies
	bool operator==(Movie&); // compares 2 movies for equality 
};

#endif // COMEDY_H
