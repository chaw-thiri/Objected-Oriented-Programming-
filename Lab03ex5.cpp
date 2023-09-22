#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
namespace shape {
	double rec_area(int, int);
	double tri_area(int, int);
	double cir_area(int);

}

int main() {

	cout << "Area of the Rectangle(W:20, L:10): ";
	cout << shape::rec_area(20, 10) << endl;

	cout << "Area of Triangle(b:20, h:10): ";
	cout << shape::tri_area(20, 10) << endl;

	cout << "Area of Circle(r:20): ";
	cout << shape::cir_area(20) << endl;

	return 0;

}
double shape::rec_area(int a, int b) {
	return a * b;
}
double shape::tri_area(int a, int b) {
	return (0.5 * a * b);
}
double shape::cir_area(int a) {
	return (M_PI * a * a);

}
