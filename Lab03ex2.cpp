#include <iostream>
using namespace std;

// function prototype
void display(char);
void display(int);
void display(double);
int main() {
	display('A');
	display(1234);
	display(123.4);
	return 0;
}
void display(char A) {
	cout << "char type: " << A << endl;
}
void display(int A) {
	cout <<"int type: " << A << endl;
}
void display(double A) {
	cout <<"doub
