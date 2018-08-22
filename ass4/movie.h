#ifndef MOVIE_H
#define MOVIE_H

#include<string>

using namespace std;

class Movie {
public:
	Movie();			              // default constructor 
	explicit Movie(const Movie&);		             // copy constructor 
	virtual ~Movie();

	//getters & setters for class data members 
	int getStock();
	void setStock(int);
	string getMovieType();
	string getDirector();
	void setDirector(string);
	string getTitle();
	void setTitle(string);
	int getYearOfRelease();
	void setYearOfRelease(int);
	string getMajorActorFirstName();
	string getMajorActorLastName();
	void setMajorActorFirstName(string);
	void setMajorActorLastName(string);
	int getMonthOfRelease();
	void setMonthOfRelease(int);

	// overloaded operator pure virtual methods
	virtual bool operator==(Movie&);
	virtual bool operator<(Movie&);
	virtual bool operator>(Movie&);
	
protected:
	// stores the type of the movie. F for comedy. D for drama. C for comedy.
	string movieType;
	int stock; // this will represent the available stock of the movie 
	string director; // stores the name of the director of the movie
	string title; // stores the title of the movie
	int yearOfRelease; // stores the year of release of the movie 
	string movieCode; // is D for DVD
	string majorActorFirstName; // stores major actor's first name 
	string majorActorLastName; // stores major actor's last name 
	int monthOfRelease; // stores the month of release of the movie 
};

#endif // MOVIE_H