# RouteMap
Implementation of two classes, City and RouteMap. A route from origin city to destination is determined (if possible) by the use of backtracking using a stack.

A "city" is the main object that was constructed and used in this project. In addition to common member functions and data members 
of a city class, a city also has a private data member called adjacentCities which is a vector of city objects containing the cities in which
a flight from the current city is possible.

A "route map" is where the bulk of this project takes place. It includes all the other files (city, node, linked-list, precond-vio-except).
RouteMap has a member function called isRoute that implements the recursive backtracking. A stack of city objects is the chosen data structure. 
