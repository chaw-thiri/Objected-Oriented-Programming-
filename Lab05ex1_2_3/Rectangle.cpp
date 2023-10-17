#include <iostream>
using namespace std;
#include "Point.h"
#include "Rectangle.h"

bool Rectangle::InitMembers(const Point& ul, const Point& dr) { // will pass two objects
	// check whether ul is in upper left position and lr in the lower right position

	if ((ul.GetX() > dr.GetX()) || (ul.GetY() > dr.GetY())) return false;
	m_downLeft = ul;
	m_upRight = dr;
	return true;
}
void Rectangle::ShowRecInfo() const { /// read only
	cout << "LeftTop: [ " << m_downLeft.GetX() << ", " << m_downLeft.GetY() << "],\n";
	cout << "RightBottom: [ " << m_upRight.GetX() << ", " << m_upRight.GetY() << "]\n\n";
}


// the third point which we need to check for the location is passed into the IsInside function as an object.
// In order to be inside the rectangle, the point must lie between left and right boundries as well as upper and lower boundries 

bool Rectangle::IsInside(const Point& pt) {
	int x = pt.GetX();
	int y = pt.GetY();
	return ((x > m_downLeft.GetX()) && (x < m_upRight.GetX()) && ((y > m_downLeft.GetY()) && (y < m_upRight.GetY())));

}
