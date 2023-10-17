#include <iostream>
#include <string> // to use string
using namespace std;
class Person {
public: // making the variables public so that it can be easily accessed from main function
	string m_name;
	string m_sex;
	int m_age;
	string m_gmail;
	void introduceMyself() {
		cout << "My name is " << m_name << "." << endl;
		cout << "I am " << m_sex << " and " << m_age << " years old." << endl;
		cout << "My email address is " << m_gmail << "." << endl;
	}
};
int main() {
	Person ryu = { "Victor Ryu", "male", 30, "IGS2130v1@inha.ac.kr" };
	Person laura = { "Laura Lee", "female", 23,"IGS2130v2@inha.ac.kr" };
	ryu.introduceMyself();
	cout << endl;
	laura.introduceMyself();
	return 0;
}