#include <iostream>
#include "SavingAccount.h"
#include "Account.h"
using namespace std;



void SavingAccount::Deposit(double money) {
    double interest = (money * m_interest_rate) / 100;
    
    Account::Deposit(interest);
   
}