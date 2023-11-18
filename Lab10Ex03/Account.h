#pragma once
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

// account class
class Account {  // default contructor 
private:
	int m_id;
	double m_balance;
	char* m_cusName = nullptr;

public:
	Account() {
		m_id = 0;
		m_balance = 0;
	}
	Account(int id, double balance, const char* name) :   // constructor
		m_id{ id }, m_balance{ balance }
	{
		m_cusName = new char[strlen(name) + 1];
		strcpy_s(m_cusName, strlen(name) + 1, name);
	}

	// COPY constructor 
	Account(const Account& acc) :
		m_id{ acc.m_id }, m_balance{ acc.m_balance }
	{
		m_cusName = new char[strlen(acc.m_cusName) + 1];
		strcpy_s(m_cusName, strlen(acc.m_cusName) + 1, acc.m_cusName);
	}

	~Account() {
		delete[] m_cusName;    // delete the dynamic memory allocated  
	}
	int GetBalance(void) const;
	int GetAccID(void) const;
	virtual void Deposit(double money);
	int Withdraw(double money);
	void ShowAccInfo(void) const;

};



#endif