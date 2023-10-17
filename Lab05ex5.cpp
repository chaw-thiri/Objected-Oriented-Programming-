#include <iostream>

using namespace std;
// class Number is created with public variables and methods so let them accessible from main function
// m_num is declared as a float so that it can perform decimal calculations.

class Number {
public:
	float m_num;
	float setValue(float n) {
		m_num = n;
		return m_num;
	}
	float getValue() {
		return m_num;
	}
	float add(float n) {
		m_num += n;
		return m_num;
	}
	float sub(float n) {
		m_num -= n;
		return m_num;
	}
	float mul(float n) {
		m_num *= n;
		return m_num;
	}
	float div(float n) {
		m_num /= n;
		return m_num;
	}

};



int main() {
	Number n1, n2;
	n1.setValue(0.0);
	cout << "n1 : " << n1.getValue() << endl;
	cout << "n1 += 10.5 : " << n1.add(10.5) << endl;
	cout << "n1 -= 1.5 : " << n1.sub(1.5) << endl;
	cout << "n1 *= 3.0 : " << n1.mul(3.0) << endl;
	cout << "n1 /= 9.0 : " << n1.div(9.0) << endl;
	cout << "n2 = n1 : " << n2.setValue(n1.getValue());
	return 0;
}