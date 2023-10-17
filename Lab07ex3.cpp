#include <iostream>
using namespace std;


const int NAME_LEN = 40;    // size for char array pointer 
const int MAX_ACC = 100;	// size for object arrray 

enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
private:
	int m_id;
	double m_balance;
	char* m_cusName = nullptr;

public:
	Account(int id, double balance, const char* name) :   // constructor
		m_id{ id }, m_balance{ balance }
	{
		m_cusName = new char[strlen(name) + 1];   
		strcpy_s(m_cusName, strlen(name) + 1, name);
	}
	~Account() {
		delete[] m_cusName;    // delete the dynamic memory allocated  
	}
	int GetAccID(void) const { // const make sure that no modification will be done to m_id;
		return m_id;
	}

	void Deposit(double money) {
		m_balance += money;
	}
	int Withdraw(double money) {
		// withdrawl would not be allowed if there aint enough balance
		if (money <= m_balance) {    
			cout << "Balance before withdrawl: " << m_balance << endl;
			m_balance -= money;
			cout << "Balace after withdrawl: " << m_balance << endl;
			return 0;
		}
		return -1;
	}
	void ShowAccInfo(void) {
		cout << "Account ID :" << m_id << endl;
		cout << "Account Name :" << m_cusName << endl;
		cout << "Balance: " << m_balance << endl;
		cout << endl;
	}
};

Account* accArr[MAX_ACC];    // building an array of 100 Account objects
int accNum = 0;

//prototypes for general functions
void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);
int  GetAccIdx(int);


int main(void) {
	int choice;

	while (1) {
		ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;

		switch (bank(choice)) {
		case bank::MAKE:
			MakeAccount();
			break;
		case bank::DEPOSIT:
			DepositMoney();
			break;
		case bank::WITHDRAW:
			WithdrawMoney();
			break;
		case bank::INQUIRE:
			ShowAllAccInfo();
			break;
		case bank::EXIT:
			for (int i = 0; i < accNum; ++i) {
				delete accArr[i]; // do not require this if you are using structure instead of class
			}
			return 0;
		
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu() {
	cout << "-----Menu------" << endl;
	cout << "1. Make Account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawl" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Exit program" << endl;

}

void MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	double balance;

	if (accNum >= MAX_ACC) {     
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

	// now new value will be added to the Account objects created here >>>Account* accArr[MAX_ACC]; 

	accArr[accNum] = new Account{ id,balance,name }; // **** object with dynamic memory allocation , delete in exit 
	accNum++;

}
void DepositMoney(void) {
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

void WithdrawMoney(void) {
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


void ShowAllAccInfo(void) {
	if (accNum == 0) {
		cout << "You don't have any account.\n";
		return;
	}
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
	}
}
int GetAccIdx(int id) {
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			return i;
		}
	}
	return -1;
}
