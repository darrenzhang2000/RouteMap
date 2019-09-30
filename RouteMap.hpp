//Darren Zhang
//July 4, 2019
// interface of Route Map 

#ifndef RoadMap_HPP
#define RoadMap_HPP

#include "City.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <stack> 

class RouteMap{
public:
	// Constructors
	
	//Default Constructor
	//Creates an object of the RouteMap class with placeholder initial values when no information is provided.
	RouteMap();
	
	//Parameterized Constructor 
	//@pre the input file is expected to be in CSV (comma separated value)
	//@param input_file_name the name of the input csv file
	//@post City objects are added to the vector locations_.
	RouteMap(std::string input_file_name);


	/**
	@param input_file_name of a csv file representing a route map where the first     
		    line is a comma-separated list of city names, and the remainder is a
   	    comma-separated list of city-pairs of the form A-B, indicating that B
   	    is adjacent to A (i.e. there is an arrow in the map going from A to B)
	@post this depends on your design, the input data representing the map must
	      have been stored. Adjacent cities must be stored and explored in the
	      same order in which they are read from the input file 
	**/
	bool readMap(std::string input_file_name);
	
	/**
	@return a pointer to the city found at position, where
	     0 <= position <= n-1, and n is the number of cities,
	     and cities are stored in the same order in which they appear
	     in the input file
	**/
	City* getCity(size_t position); 
	
	/**
	@return true if there is a route from origin to destination, false otherwise
	@post if a route is found from origin to destination, it will print it to
	      standard output in the form â€œORIGIN -> ... -> DESTINATION\nâ€**/
	bool isRoute(City* origin, City* destination);
   
	//prints path if found 
	//@pre none
	//@param list.empty != true
	//@ post locations of list 
	void printLocations(std::stack<City*> list);
   
	//Finds a City in the locations_ 
	//@param name nonempty
	//@return city pointer
	City* findCity(std::string name);
   
private:
	std::vector<City*> locations_;
};

#endif