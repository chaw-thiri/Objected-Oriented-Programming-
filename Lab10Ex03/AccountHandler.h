#pragma once
#ifndef  _ACCOUNTHANDLER_H_
#define _ACCOUNTHANDLER_H_
#include "Account.h"


const int NAME_LEN = 40;    // size for char array pointer 
const int MAX_ACC = 100;	// size for object arrray 

enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
// Account Handler class
class AccountHandler {
private:
	Account* accArr[MAX_ACC] = { NULL, };    // building an array of 100 Account objects, class pointer
	// setting null makes it more memory efficient
	int accNum;
public:
	AccountHandler(int num = 0) : accNum{ num } {}
	~AccountHandler() {
		for (int i = 0; i < accNum; i++) {
			delete accArr[i]; // removing the members inside the array
		}

	}
	void ShowMenu(void);
	void MakeAccount(void);
	void MakeSavingAccount(void);
	void MakeHighCreditAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	int  GetAccIdx(int) const;
	int GetAccNum(int) const { return accNum; }

};

#endif // ! "AccountHandler.h"