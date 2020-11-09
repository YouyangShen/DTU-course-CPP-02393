#include "BankAccount.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount(int no, string own, double bal) {
    this->owner = own;
    this->number = no;
    this->balance = bal;
}

void BankAccount::print() const {
    cout << "Account number " << this->number << " owned by " << this->owner << " contains " << this->balance << endl;
}

bool BankAccount::transferMoney(BankAccount &to, double value) {
    if (value < 0 || this->balance < value) {
		cout << "Transfer failed" << endl;
		return false;
	} else {
		this->balance -= value;
		to.balance += value;
		cout << "Transfer succeeded" << endl;
		return true;
	}
}

bool BankAccount::transferMoneyBAD(BankAccount to, double value) {
    if (value < 0 || this->balance < value) {
		cout << "Transfer failed" << endl;
		return false;
	} else {
		this->balance -= value;
		to.balance += value;
		cout << "Transfer succeeded" << endl;
		return true;
	}
}

BankAccount::~BankAccount() {
    cout << "*** Destructor invoked for bank account of " << this->owner << endl;
}
