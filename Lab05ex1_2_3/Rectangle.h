#pragma once
#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h" // rectange needs points


//EXERCISE 2
class Rectangle {
public:
	Point m_downLeft;
	Point m_upRight;

public:
	bool InitMembers(const Point& ul, const Point& lr); // pass two objects
	void ShowRecInfo() const;   // for getting value only
	//EXERCISE 3
	bool IsInside(const Point& pt);    // get the value of the new point and compare it with the corner points

};


#endif // __RECTANGLE_H_
