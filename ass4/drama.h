#ifndef DRAMA_H
#define DRAMA_H

#include<string>
#include "movie.h"
using namespace std;

// class that inherits from class Movie 
class Drama : public Movie
{
public:
	// constructor that takes in arguments for all data members of movie 
	// that are used to instantiate a drama movie 
	Drama(int stock, string director, string title, int yearOfRelease,
		string movieCode);

	bool operator==(Movie&); // compares 2 movies for equality 
	bool operator<(Movie&); // less than comparison of 2 movies
	bool operator>(Movie&); // greater than comparison of 2 movies
};

#endif // DRAMA_H
