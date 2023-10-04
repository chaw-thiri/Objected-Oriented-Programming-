#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include <iostream>
using namespace std;

class Triangle {
private:
	double m_base;
	double m_height;

public:
	// constructor with two parameters
	Triangle(double base, double height) : m_base{base}, m_height{height} {

	}
	// return the size of the triangle base
	double getBase() const { return m_base; }
	// return the size of the triangle height
	double getHeight() const { return m_height; }
	// return the triangle area

	double area() const {
		return (0.5 * m_base * m_height);
	}


	// destructor
	~Triangle() {
		cout << "Destructor: base: " << m_base << ", height : " << m_height << endl;
	}
};

#endif