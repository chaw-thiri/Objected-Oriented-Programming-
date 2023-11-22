#include <iostream>
using namespace std;

// create fraction class to store fraction objects
class Fraction {
private:
	int m_numerator;
	int m_denomerator;

public:
// constructor 
	Fraction(int numerator = 0, int denomerator = 1) {
		m_numerator = numerator;
		m_denomerator = denomerator;
	}

	// overloaded operators
	friend ostream& operator<< (ostream&, const Fraction&) ;
	friend Fraction operator*(const Fraction&, const Fraction&);
	friend Fraction operator-(const Fraction&, const Fraction&);
	friend Fraction operator+(const Fraction&, const Fraction&);
	Fraction operator-() {
		return Fraction(-m_numerator,  m_denomerator);
	}
	friend Fraction minimizer(const Fraction&);

};
Fraction minimizer(const Fraction& a) {
	Fraction new_a;
	new_a.m_denomerator = a.m_denomerator;
	new_a.m_numerator = a.m_numerator;
	for (int i = a.m_denomerator; i >= 2; --i) {
		if (a.m_denomerator % i == 0 && a.m_numerator % i == 0) {
			new_a.m_denomerator /= i;
			new_a.m_numerator /= i;
		}
	}


	return new_a;
}

Fraction operator-(const Fraction& a, const Fraction& b) {
	Fraction minus, new_a, new_b;
	new_b.m_denomerator,new_a.m_denomerator = a.m_denomerator * b.m_denomerator;
	new_a.m_numerator = a.m_numerator * b.m_denomerator;
	//new_b.m_denomerator = a.m_denomerator * b.m_denomerator;
	new_b.m_numerator = b.m_numerator * a.m_denomerator;
	minus.m_denomerator = new_a.m_denomerator;		
	minus.m_numerator = new_a.m_numerator - new_b.m_numerator;
	minus = minimizer(minus);



	return minus;
}
Fraction operator+(const Fraction& a, const Fraction& b) {
	Fraction plus, new_a, new_b;
	new_b.m_denomerator, new_a.m_denomerator = a.m_denomerator * b.m_denomerator;
	new_a.m_numerator = a.m_numerator * b.m_denomerator;
	//new_b.m_denomerator = a.m_denomerator * b.m_denomerator;
	new_b.m_numerator = b.m_numerator * a.m_denomerator;
	plus.m_denomerator = new_a.m_denomerator;
	plus.m_numerator = new_a.m_numerator + new_b.m_numerator;

	plus = minimizer(plus);


	return plus;

}

ostream& operator<<(ostream& out , const Fraction& a) {
	
	
	if (a.m_denomerator < 0) {
		out << -a.m_numerator << "/" << -a.m_denomerator;
	}
	else {
		out << a.m_numerator << "/" << a.m_denomerator;
	}
	return out;

}
Fraction operator*(const Fraction& a, const Fraction& b) {
	Fraction product;
	product.m_denomerator = a.m_denomerator * b.m_denomerator;
	product.m_numerator = a.m_numerator * b.m_numerator;

	product = minimizer(product);

	return product;
	
}


int main() {


		Fraction f1{ 1,2 }, f2{ 3,4 }, f4{ -1,2 }, f5{ 1,-2 }, f6{ -1,-2 };
		cout << f1 << "," << f2 << endl;
		cout << -f1 << ", " << -f2 << endl;
		cout << -(-f1) << endl;

	
		return 0;
}

# the fuctions and classes are the same for every exercises, only the main function changes a little bit
