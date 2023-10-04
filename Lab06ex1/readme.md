# point.h   
*	Point has two components: x and y. As a rule, variables are declared private, and functions are declared public to prevent unwanted modifications of the root variables.   
*  Thus, to initialize these private variables, we used constructors. Here, there are two headers for the Point object: default one without any parameters and another constructor with two parameters. If no arguments are passed, the default one would be called, and the coordinate would be set automatically as (0, 0).    
* Here, get x, get y, and get are getters functions which are used to retrieve m_x and m_y form the point object and provide them to the user.   
# main.cpp    
*	Firstly, point.h is imported into the main.cpp using include keyword.    
p.s all the variables are initialized using the brace initialization.    
