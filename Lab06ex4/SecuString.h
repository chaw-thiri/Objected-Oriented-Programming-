#pragma once
#ifndef _SECUSTRING_H_
#define _SECUSTRING_H_

#include <iostream>
using namespace std;
#include <string>

class SecuString {
private:
	string m_storedString;
	string m_password;
public:
	SecuString(string str, string password) : m_storedString{str}, m_password{password}
	{

	}
	bool SetMessage(string message, string password) {
		if (m_password == password) {
			m_storedString = message;
			return 1;
		}
		else return 0;
	}
	string GetMessage(string password) {
		if (m_password == password)
			return m_storedString;
		else return "No real stored message. Invalid Password. ";

	}

	bool ChangePW(string old_pw, string new_pw) {
		if (m_password == old_pw) {
			m_password = new_pw;
			return 1;
		}
		else return 0;
	}
};


#endif