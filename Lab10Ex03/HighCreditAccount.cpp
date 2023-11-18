#include <iostream>
#include "HighCreditAccount.h"
#include "Account.h"
using namespace std;

void HighCreditAccount::Deposit(double money) {

	Account::Deposit((money * m_special_interest_rate) / 100);

}
