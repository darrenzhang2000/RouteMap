//RouteMap.cpp
//Darren Zhang
//July 4, 2019
// Route Map implemention. isRoute finds and prints a route that can be used to get from origin city to destination

#include "RouteMap.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack> 

// Constructors
	
	//Default Constructor
	RouteMap::RouteMap(){
	}
	
	//Parameterized Constructor 
	//@param input_file_name of csv file 
	//@post City objects are added to locations_.
	RouteMap::RouteMap(std::string input_file_name){
		readMap(input_file_name);
	}


	/**
	@param input_file_name of a csv file representing a route map where the first     
		    line is a comma-separated list of city names, and the remainder is a
   	    comma-separated list of city-pairs of the form A-B, indicating that B
   	    is adjacent to A (i.e. there is an arrow in the map going from A to B)
	@post this depends on your design, the input data representing the map must
	      have been stored. Adjacent cities must be stored and explored in the
	      same order in which they are read from the input file 
	**/
	bool RouteMap::readMap(std::string input_file_name){
	
		std::ifstream file;
		file.open(input_file_name.c_str());
		
		std::string city_string;
		std::string line;
		std::string first;
		std::string second;
		//creates cities 
		std::getline(file, line); 
		while(line != ""){
			if(line.find_first_of(',') == -1){
				city_string = line;
				locations_.push_back(new City(city_string));
				line = "";
			}
			else{
				city_string = line.substr(0,line.find_first_of(','));
				locations_.push_back(new City(city_string));
				line = line.substr(line.find_first_of(',') + 1);
			}
		}
		
		//Creaties adacent cities 
		std::getline(file, line); 
		while(line != ""){
			if(line.find_first_of(',') == -1){
				city_string = line;
				findCity(	city_string.substr(0,city_string.find_first_of('-')) ) -> addAdjacentCity(findCity(city_string.substr(city_string.find_first_of('-') + 1)));
				line = "";
			}
			else{
				city_string = line.substr(0,line.find_first_of(','));
				findCity(city_string.substr(0,city_string.find_first_of('-'))) -> addAdjacentCity(findCity(city_string.substr(city_string.find_first_of('-') + 1)));
				line = line.substr(line.find_first_of(',') + 1);
			}
		}
		
		
		return true;
	}
	
	/**
	@return a pointer to the city found at position, where
	     0 <= position <= n-1, and n is the number of cities,
	     and cities are stored in the same order in which they appear
	     in the input file
	**/
	City* RouteMap::getCity(size_t position){
		return locations_[position];
	}
	
	/**
	@return true if there is a route from origin to destination, false otherwise
	@post if a route is found from origin to destination, it will print it to
	      standard output in the form â€œORIGIN -> ... -> DESTINATION\nâ€**/
	bool RouteMap::isRoute(City* origin, City* destination){
	
		std::stack<City*> path;
		path.push(origin);
		path.top() -> setVisited(true);

		while(path.top() != destination){
			// add city to stack
			if(path.top() -> notVisitedAdjacentCities()){
				for(City* city: path.top() -> getAdjacentCities()){
					if (!(city -> getVisited())){ //prevents infinite loops
						city -> setVisited(true);
						path.push(city);
					    break;
					}
				}
			}
			//backtrack
			else{
				path.pop();
	    		//no possible path from origin to destination
        		if(path.empty()){
			        return false;
		        }
			}
		}
		printLocations(path);
		return true;
	} 
   
	// prints path if found
	//@param list list of cities
	//@post location of cities 
	void RouteMap::printLocations(std::stack<City*> list){
		std::stack<City*> result;
		while (!list.empty() ){
			result.push(list.top());
			list.pop();
		}
		while (!result.empty()){
			if (result.size() == 1){
				std::cout << result.top() -> getName() << std::endl;
				result.pop();
			}
			else{
				std::cout << result.top() -> getName() << " -> ";
				result.pop();
			}
		}
	}
	
	//Finds a City in the locations_ 
	//@param name name of the city
	//@return City* pointer to a city 
	City* RouteMap::findCity(std::string name){
		for(int i = 0; i < locations_.size(); i++){
			if (locations_[i] -> getName() == name){
				return locations_[i];
			}
		}
	}
	
	
	