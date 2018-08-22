#include<string>
#include"movie.h"
using namespace std;

// default constructor 
Movie::Movie() {
	movieType = "";
	stock = 0; 
	director = ""; 
	title = ""; 
	yearOfRelease = 0;
	movieCode = "";
	majorActorFirstName = "";
	majorActorLastName = "";
	monthOfRelease = 0;
}

// copy constructor 
Movie::Movie(const Movie &other) {
	if (movieType != other.movieType) return;

	stock = other.stock;
	director = other.director;
	title = other.title;
	yearOfRelease = other.yearOfRelease;
	movieCode = other.movieCode;
	majorActorFirstName = other.majorActorFirstName;
	majorActorLastName = other.majorActorLastName;
	monthOfRelease = other.monthOfRelease;
}

// default desctructor 
Movie::~Movie() {}

int Movie::getStock() {
	return stock;
}
void Movie::setStock(int input) {
	stock = input;
}
string Movie::getMovieType() {
	return movieType;
}
string Movie::getDirector() {
	return director;
}
void Movie::setDirector(string input) {
	director = input;
}
string Movie::getTitle() {
	return title;
}
void Movie::setTitle(string input) {
	title = input;
}
int Movie::getYearOfRelease() {
	return yearOfRelease;
}
void Movie::setYearOfRelease(int input) {
	yearOfRelease = input;
}
string Movie::getMajorActorFirstName()
{
	return majorActorFirstName;
}
void Movie::setMajorActorFirstName(string name)
{
	majorActorFirstName = name;
}
string Movie::getMajorActorLastName()
{
	return majorActorLastName;
}
void Movie::setMajorActorLastName(string name)
{
	majorActorLastName = name;
}
int Movie::getMonthOfRelease()
{
	return monthOfRelease;
}
void Movie::setMonthOfRelease(int month)
{
	monthOfRelease = month;
}

// virtual method to be overloaded by children 
bool Movie::operator==(Movie &other) {
	return false;
}
// virtual method to be overloaded by children 
bool Movie::operator<(Movie &other) {
	return false;
}
// virtual method to be overloaded by children 
bool Movie::operator>(Movie &other) {
	return false;
}