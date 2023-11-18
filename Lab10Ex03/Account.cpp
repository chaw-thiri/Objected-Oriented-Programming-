#include <iostream>
#include "Account.h"
using namespace std;




int Account::GetAccID(void) const { // const make sure that no modification will be done to m_id;
	return m_id;
}
int Account::GetBalance(void) const {
	return m_balance;
}
void Account::Deposit(double money) {
	m_balance += money;
}


int Account::Withdraw(double money) {
	// withdrawl would not be allowed if there aint enough balance
	if (money <= m_balance) {
		cout << "Balance before withdrawl: " << m_balance << endl;
		m_balance -= money;
		cout << "Balace after withdrawl: " << m_balance << endl;
		return 0;
	}
	return -1;
}
void Account::ShowAccInfo(void) const {
	cout << "Account ID :" << m_id << endl;
	cout << "Account Name :" << m_cusName << endl;
	cout << "Balance: " << m_balance << endl;
	cout << endl;
}



