
#define _USE_MATH_DEFINES
#include <cmath>
#pragma once
#ifndef _CIRCLE_H
#define _CIRCLE_H
#include "Point.h"
#include <iostream>
using namespace std;
const double PI  = 3.14159265358979323846;
class Circle {
private:
	Point m_pt;
	double m_radius;
public:
//constructors
	Circle() : m_pt{ 0,0 }, m_radius{ 0 } { // member initializer array

	}
	Circle(const Point& p, double radius) : m_pt{ p }, m_radius{ radius } { // constructor with two parameters

	}
	Circle(double x, double y, double radius) : m_pt{ x,y }, m_radius{ radius } { // constructor with three parameters

	}
// functions
	void info() {
		cout << "Center: [" << m_pt.getx() << ", " << m_pt.gety() << "], Radius: " << m_radius << endl;
	}

	// return area
	double area() {
		//return  pow(m_radius,2) * M_PI;   
		return (pow(m_radius, 2) * PI);
	}
	//return center
	Point center() const {
		return m_pt;
	}
	// return radius
	double radius() {
		return m_radius;
	}
	
	bool IsInside(const Point& new_pt) {
		// the new point will be inside the circle if its coordinates lie between central point+/- radius
		return (((new_pt.getx() > (m_pt.getx() - m_radius))
			&& (new_pt.getx() < (m_pt.getx() + m_radius))
			&& (new_pt.gety() > (m_pt.gety() - m_radius))
			&& (new_pt.gety() < (m_pt.gety() + m_radius))
					) ? 1 : 0);

	}

// destructors
	~Circle() {
		cout << "Destruction of a class instance\n";
		info();
	}

};



#endif