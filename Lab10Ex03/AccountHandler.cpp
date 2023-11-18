#include <iostream>
#include "AccountHandler.h"
#include "SavingAccount.h"
#include "HighCreditAccount.h"

using namespace std;


void AccountHandler::ShowMenu() {
	cout << "-----Menu------" << endl;
	cout << "1. Make Account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawl" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Exit program" << endl;

}

void AccountHandler::MakeAccount(void) {
	int accType;


	if (accNum >= MAX_ACC) {
		cout << "Sorry! cannot make an account anymore." << endl;
		return;
	}
	cout << "[Select Account Type]" << endl;
	cout << "1. Saving Account" << endl;
	cout << "2. High Credit Account" << endl;
	cout << "Select : ";
	cin >> accType;
	while (accType == 1 || accType == 2) {
		// while loop will reject the invalid user inputs
		if (accType == 1) {
			MakeSavingAccount();
			return;
		}
		else if (accType == 2) {
			MakeHighCreditAccount();
			return;
		}
		else
			cout << "Invalid input. ";
	}



}

void AccountHandler::MakeSavingAccount(void) {
	int id;
	double rate;
	char name[NAME_LEN];
	double balance;
	cout << "[Make Saving Account]" << endl;

	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> balance;
	cout << "Interest rate: ";
	cin >> rate;
	//rate /= 100;
	cout << endl;

	if (GetAccIdx(id) != -1) {
		cout << "Error: Existing account ID" << endl;
		return;
	}
	if (accNum >= 100) {
		cout << "The bank is full, cannot accept more members\n";
		return;
	}

	// now new value will be added to the Account objects created here >>>Account* accArr[MAX_ACC]; 

	accArr[accNum] = new SavingAccount{ id,balance,name,rate }; // **** object with dynamic memory allocation , delete in exit 


	accNum++;


}

void AccountHandler::MakeHighCreditAccount(void) {
	int id, credit;
	double rate, special;
	char name[NAME_LEN];
	double balance;
	cout << "[Make High Credit Account]" << endl;

	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> balance;
	cout << "Interest rate: ";
	cin >> rate;

	cout << "Credit Rating (A:1, B:2, C:3): ";
	cin >> credit;
	special = (credit == 1) ? 7 : (credit == 2) ? 4 : 2;


	cout << endl;

	if (GetAccIdx(id) != -1) {
		cout << "Error: Existing account ID" << endl;
		return;
	}
	if (accNum >= 100) {
		cout << "The bank is full, cannot accept more members\n";
		return;
	}

	// now new value will be added to the Account objects created here >>>Account* accArr[MAX_ACC]; 

	accArr[accNum] = new HighCreditAccount{ id,balance,name,rate,special }; // **** object with dynamic memory allocation , delete in exit 


	accNum++;


}




void AccountHandler::DepositMoney(void) {
	double money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			return;
		}


	}cout << "This ID is not valid." << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
	double money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdrawal amount: ";
	cin >> money;

	int result = -1;  // to check whether the account has enough balance, 

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			result = accArr[i]->Withdraw(money);
			if (result == -1) {
				cout << "You do not have enough balance" << endl;
				return;
			}
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;

}


void AccountHandler::ShowAllAccInfo(void) const {
	if (accNum == 0) {
		cout << "You don't have any account.\n";
		return;
	}
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
	}
}
int AccountHandler::GetAccIdx(int id) const {
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			return i;
		}
	}
	return -1;
}


