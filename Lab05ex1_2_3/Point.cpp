#include <iostream>
#include "Point.h"
using namespace std;

// check if the points are in the first quadrant
bool Point::isInRange(int pos) {
	return  (pos <= POSMAX && pos >= POSMIN);  // return true or false after checking the condition
}

// if the points are in range, then these points are passed into the point class
bool Point::SetX(int xpos) {

	if (!isInRange(xpos)) {
		return false;
	}
	m_x = xpos;
	return true;
}
bool Point::SetY(int ypos) {

	if (!isInRange(ypos)) {
		return false;
	}
	m_y = ypos;
	return true;
}

// getting the value of the points from the Point object (class) 
int Point::GetX() const {
	return m_x;
}
int Point::GetY() const {
	return m_y;
}
// same concept as setX, setY functions
bool Point::InitMembers(int xpos, int ypos) { // pass two numbers 
	if (!isInRange(xpos) || !isInRange(ypos)) {
		// initialize the point if the points are in range
		return false;
	}

	m_x = xpos;
	m_y = ypos;
	return true;
