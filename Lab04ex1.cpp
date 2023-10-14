// do not use boolean return value from ascending and decending functions
#include <iostream>
using namespace std;

void sort3(double&, double&, double&, bool(*)(double&, double&));
void print3(const double&, const double&, const double&);
void swap2(double&, double&);
bool ascending(double&, double&);
bool descending(double&, double&);

int main() {
	double na1 = 10.3, na2 = -2.1, na3 = 8.0;
	double nd1 = 10.3, nd2 = -2.1, nd3 = 8.0;



	cout << "Before sort: "; print3(na1, na2, na3);

	sort3(na1, na2, na3, ascending);
	sort3(nd1, nd2, nd3, descending);

	cout << "After sort(ascending): ";  print3(na1, na2, na3);
	cout << "After sort(descending): "; print3(nd1, nd2, nd3);

	return 0;

}

void print3(const double& num1, const double& num2, const double& num3) {
	cout << num1 << " " << num2 << " " << num3 << endl;
}


void sort3(double& n1, double& n2, double& n3, bool(*f)(double&, double&)) {
	f(n1, n2);
	f(n1, n3);
	f(n2, n3);

}
bool ascending(double& num1, double& num2) {
	if (num2 < num1) swap2(num1, num2);
	return true;

}
bool descending(double& num1, double& num2) {
	if (num2 > num1) swap2(num1, num2);
	return true;
}

void swap2(double& i, double& j) {
	double temp;
	temp = i;
	i = j;
	j = temp;
}
