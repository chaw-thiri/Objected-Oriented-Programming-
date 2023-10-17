#include <iostream>
using namespace std;
class Rectangle {
private:
	double m_width = 0;
	double m_height = 0; // class member declaration
public:
	Rectangle* setWidth(double w) { 
		m_width = w;
		return this;   // returning object using this pointer so that other function can be called on this returned  (chaining)
	}
	Rectangle* setHeight(double h) {
		m_height = h;
		return this;
	}
	void Display(void) {
		cout << "Width = " << m_width << " Height = " << m_height << endl;
	}
};
int main() {
	Rectangle rect;
	rect.Display();
	rect.setWidth(10)->setHeight(20)->Display();   // chaining using this pointer
	return 0;
}
