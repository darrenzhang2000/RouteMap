//Title: City.hpp
//Name: Darren Zhang
//Last Updated: July 3rd, 2019

// This is the interface of the City class.

#ifndef City_
#define City_

#include <string>
#include <iostream>
#include <vector>

class City{
public:
	
	//Default Constructor
	City();
	
	//Parameterized Constructor 
	//creates city object with given name
	//@pre none
	//@param name the name of the City object 
	//@param visited the visit status of the City object 
	//@post creates city object
	City(std::string name);

	
	//accessor 
	//Returns if the City has been visited.
	//@pre none
	//@return visited_  value
	bool getVisited() const;

	//accessor 
	//Returns the City's name.
	//@pre has to have name
	//@return name_ of the City 
	std::string getName() const;
	
	// Returns  adjacentCities.
	//@pre adjacentCities.size() greater than 0.
	//@return adjacentCities of the City 
	std::vector<City*> getAdjacentCities();
		
	//mutator
	//Changes visited_ to status.
	//@pre status == true || status == false
	//@param status to be stored in visited_. 
	void setVisited(bool status);
	
	//Changes the name_ to name.
	//@pre nonempty name
	//@param name name of city
	void setName(std::string name);	

	//Adds a City to Adjacent
	//@pre name nonempty
	//@param pointer to cities
	void addAdjacentCity(City* name);
	
	//Checks forany not-visited adjacent cities.
	bool notVisitedAdjacentCities();


private:
	bool visited_;
	std::string name_;
	std::vector<City*> adjacentCities;
};

#endif
