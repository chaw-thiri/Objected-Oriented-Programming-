#include <iostream>
using namespace std;

class Calculate {
private:
    double m_value;
public:
    char operations[5] = {NULL,};
    double input_num[5] = {NULL,};
    double m_value_list[10] = {NULL,};
    Calculate() {
        m_value = 0;
    }
    Calculate(const Calculate& sample) {
        m_value = sample.m_value;
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
    bool lastOperation(char& op, double& value) {
        static int k = 4; // counter
        if (k >= 0) {
            
            
            op = operations[k];
            value = input_num[k];
            k--;
            if (op != NULL && value != NULL) return true;
            else return false;
        }
        return false;
    }
    void undo(void) {
        static int j = 8;
        if (j >= 0) {
            m_value = m_value_list[j];
            j--;
            return; 
        }

    }
};

int main(void) {
    bool flag;
    Calculate cc;
    int i;
    char op;
    double value;
    
    for (i = 0; i < 10; ++i) {
        cout << "Select math operator(+,-,*,/): ";
        cin >> op;
        cout << "Enter a real number for the math: ";
        cin >> value;
        if (i >= 5) {
            // store op and value from 5 to 9 inclusive
            cc.operations[i - 5] = op;
            cc.input_num[i - 5] = value;
        }

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
        cc.m_value_list[i] = cc.getValue();
        
    }
    Calculate dd{ cc };
    cout << endl << endl;
    for (i = 0; i < 10; ++i) {
        cout << "Stored the last math operation: ";
        flag = dd.lastOperation(op, value);
        if (!flag)
            cout << "None" << endl;
        else
            cout << op << ", " << value << endl;

        if (flag) {
            dd.undo();
            cout << "Undo the last math operation..." << endl;
            cout << "Value inside the class object: ";
            cout << dd.getValue() << endl;
        }
    }
    cout << "Value inside the class object: ";
    cout << dd.getValue() << endl;

    return 0;
}
