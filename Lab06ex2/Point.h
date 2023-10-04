#pragma once
#pragma once
#ifndef _POINT_H_
#define _POINT_H_
#include <iostream>
using namespace std;

class Point {
private:
	double m_x;
	double m_y;
public:
	Point() : m_x {0}, m_y{0} // member initializer array
	{

	}
	Point(double x, double y) : m_x{x}, m_y{y} // constructor with two parameters
	{ 
	}

	// display x and y value
	void info(void) {
		cout << "(x,y) = " << m_x << ", " << m_y << endl;

	}
	// get x value
	double getx(void) {
		return m_x;
	}

	// get y value
	double gety(void) {
		return m_y;
	}
	// get x and y 
	void get(double& x, double& y) {
		x = getx();
		y = gety();



	}
};

#endif
