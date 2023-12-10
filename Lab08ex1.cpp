#include <iostream>
using namespace std;
class Calculate {
private:
    double m_value;
public:
    Calculate() {
        m_value = 0;
    }
    double getValue() const {
        return m_value;
    }
    double add(double num) {
        m_value += num;
        return m_value;
    }
    double substract(double num) {
        m_value -= num;
        return m_value;
    }
    double multiply(double num) {
        m_value *= num;
        return m_value;

    }
    double divide(double num) {
        m_value /= num;
        return m_value;
    }
};

int main(void) {
    Calculate cc;
    int i;
    char op;
    double value;
    for (i = 0; i < 10; ++i) {
        cout << "Select math operator(+,-,*,/): ";
        cin >> op;
        cout << "Enter a real number for the math: ";
        cin >> value;

        switch (op) {
        case '+':
            cout << cc.getValue() << " + " << value;
            cout << " = " << cc.add(value) << endl;
            break;
        case '-':
            cout << cc.getValue() << " - " << value;
            cout << " = " << cc.substract(value) << endl;
            break;
        case '*':
            cout << cc.getValue() << " * " << value;
            cout << " = " << cc.multiply(value) << endl;
            break;
        case '/':
            cout << cc.getValue() << " / " << value;
            cout << " = " << cc.divide(value) << endl;
            break;
        }
    }
    return 0;
}
