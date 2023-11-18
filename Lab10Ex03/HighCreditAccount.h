#pragma once
#ifndef _HIGHCREDITACCOUNT_H_
#define _HIGHCREDITACCOUNT_H_
#include "SavingAccount.h"

// high credit account
class HighCreditAccount : public SavingAccount {
private:
	double m_special_interest_rate;
public:
	// default constructor

	HighCreditAccount(int id, double balance,const char* cname, double rate, double special) 
:SavingAccount(id, balance, cname, rate), m_special_interest_rate{ special }
	{
		HighCreditAccount::Deposit(balance);
	}
	virtual void Deposit(double money);

};

#endif 