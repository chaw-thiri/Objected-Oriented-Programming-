#include <iostream>
#include <string>
using namespace std;
class InhaString {
private:
	char* m_msg;
	int m_len;
public:
	InhaString() : m_msg{ NULL }, m_len{ 0 } {
		
	}
	InhaString(const char* msg) {
		int len = static_cast<int>(strlen(msg) + 1);
		m_len = len;
		m_msg = new char[len];
		strcpy_s(m_msg, len, msg);
	}
	InhaString(const InhaString& s) {
		m_len = s.m_len;
		m_msg = new char[m_len];
		strcpy_s(m_msg, s.m_len, s.m_msg);

	}
	InhaString& operator+= (const InhaString& s) {
		int total_len = m_len + s.m_len - 1;
		char* new_msg = new char[total_len];
		strcpy_s(new_msg, m_len, m_msg);
		strcpy_s(new_msg + m_len - 1, s.m_len, s.m_msg);
		delete[] m_msg;
		m_msg = new_msg;
		m_len = total_len;
		return *this;
	}
	bool operator==(const InhaString& s) {
		if (s.m_len != m_len) return false;
		for (int i = 0; i < m_len; i++) {
			if (s.m_msg[i] != m_msg[i]) {
				return false;
			}
		}
		return true;
	}
	friend istream& operator>>(istream& in, InhaString& s) {
		char buffer[256]; // Assuming a reasonable maximum word length
		in >> buffer;
		delete[] s.m_msg;
		s.m_len = static_cast<int>(strlen(buffer)) + 1;
		s.m_msg = new char[s.m_len];
		strcpy_s(s.m_msg, s.m_len, buffer);
		return in;

		
	}
	~InhaString() {
		delete[] m_msg;
	}
	friend InhaString operator+(InhaString& s1, InhaString& s2) {
		int total_len = s1.m_len + s2.m_len - 1;
		char* new_msg = new char[total_len];
		strcpy_s(new_msg, s1.m_len, (s1.m_msg) );
		strcpy_s(new_msg + s1.m_len - 1, s2.m_len, s2.m_msg);
		InhaString final{ new_msg };
		delete[] new_msg;
		return final;
	}
	friend ostream& operator<<(ostream& out, InhaString& s) {
		out << s.m_msg;
		return out;
	}
	
};





int main() {
	InhaString str1 = "I like ";
	InhaString str2 = "string class";
	InhaString str3 = str1 + str2;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	InhaString st{ str3 };

	str1 += str2;
	if (str1 == str3) {
		cout << "The two strings are identical."<<endl;
	
	}
	else {
		cout << "differnet" << endl;
		cout << str1;
		cout << endl << str3;

	}
	InhaString str4;
	cout << "Enter a string: ";
	cin >> str4;
	cout << "You entered: ";
	cout << str4 << endl;
	return 0;

}
