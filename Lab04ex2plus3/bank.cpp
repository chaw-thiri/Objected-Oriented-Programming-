#include <iostream>
#include "bank.h"
#include <string>
using namespace std;

Account accArr[MAX_ACC_NUM]; // Account array
int accNum = 0;      // # of accounts

void ShowMenu(void) {
	cout << "-----Menu------" << endl;
	cout << "1. Make Account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawl" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Delete an account" << endl;
	cout << "6. Delete all accounts " << endl;
	cout << "7. Find an account" << endl;
	cout << "8. Exit program" << endl;

}

void MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;

	if (accNum >= MAX_ACC_NUM) {
		cout << "Sorry! cannot make an account anymore." << endl;
		return;
	}


	cout << "[Make Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> balance;
	cout << endl;

	if (GetAccIdx(id) != -1) {
		cout << "Error: Existing account ID" << endl;
		return;
	}

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].cusName, NAME_LEN, name);
	//strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void) {
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "Deposit completed" << endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;
}

void WithdrawMoney(void) {
	int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdrawal amount: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			if (accArr[i].balance < money) {
				cout << "Not enough balance" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "Withdrawal completed" << endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;
}
// display the acc of the provided id
void DisplayAcc(int i) {
	cout << "Account ID: " << accArr[i].accID << endl;
	cout << "Name: " << accArr[i].cusName << endl;
	cout << "Balance: " << accArr[i].balance << endl << endl;

}
// display all accounts
void ShowAllAccInfo(void) {
	if (accNum == 0) {
		cout << "You have no account to display.\n";
		return;
	}
	for (int i = 0; i < accNum; i++) {
		DisplayAcc(i);
	}
}

int GetAccIdx(int id) {
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			return i;
		}
	}
	return -1;
}

// deleting an account

void DeleteAcc() {
	int id;
	if (accNum == 0) {
		cout << "You have no account to be deleted.\n";
		return;
	}
	ShowAllAccInfo();
	cout << "ID of the account you are going to delete: ";
	cin >> id;
	for (int i = 0; i < accNum; ++i) {
		if (accArr[i].accID == id) {
			for (int j = i; j < accNum; ++j) {

				accArr[j] = accArr[j+ 1]; // skipping the index of the array to be deleted.
			}
			

			cout << "Account Has been deleted.\n";
			
		}
	}
	accNum--;
}
// deleting all accounts

void RemoveAll() {
	/*
	* RemoveAll() function removes all the bank accounts by setting the accNum back to 0.
	*/
	string ans;
	if (accNum == 0) {
		cout << "You have no account to be deleted.\n";
		return;
	}

	cout << "You want to DELETE ALL THE ACCOUNTS!(Y/N) :";
	cin >> ans;
	if (ans == "Y" or ans =="y") {
		
		accNum = 0;
		return;
	}
	return;
}
// find an account using id
void FindAcc() {
	int id;
	cout << "Account ID : ";
	cin >> id;
	for (int i = 0; i < accNum; ++i) {
		if (accArr[i].accID == id) {
			DisplayAcc(i);
			return;
		}
	}
	cout << "Wrong Account ID or the account does not exist!" << endl;
}

