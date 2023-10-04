#pragma once
#ifndef _CIRCLE_H
#define _CIRCLE_H
#include "Point.h"
#include <iostream>
using namespace std;
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
	void info(void) {
		cout << "Center: [" << m_pt.getx() << ", " << m_pt.gety() << "], Radius: " << m_radius << endl;
	}

// destructors
	~Circle() {
		cout << "Destruction of a class instance\n";
		info();
	}

};



#endif