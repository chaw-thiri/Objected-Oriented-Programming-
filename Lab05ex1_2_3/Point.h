#pragma once

#ifndef __POINT_H__
#define __POINT_H__

const int POSMIN = 0;
const int POSMAX = 100;
// create point class
class Point {
	int m_x;
	int m_y;
	bool isInRange(int pos);

public:
	bool InitMembers(int xpos, int ypox); // pass two numbers
	bool SetX(int xpos);
	bool SetY(int ypos);
	int GetX() const;
	int GetY() const;

};

#endif // __POINT_H__
