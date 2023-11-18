#pragma once
#ifndef _SAVINGACCOUNT_H_
#define _SAVINGACCOUNT_H_
#include "Account.h"


// saving account 
class SavingAccount : public Account {
private:
	double m_interest_rate;
public:
	//	default constructor
	SavingAccount(int id, double balance,const char* cname, double rate) 
		:Account(id, balance+((balance * rate) / 100), cname), m_interest_rate{rate} {

	}

	virtual void Deposit(double money);
};


#endif