#ifndef BANKUTIL_H_
#define BANKUTIL_H_

#include <string>

using namespace std;

struct BankAccountStruct {
	int number;
	string owner;
	double balance;
};

void printAccount(const BankAccountStruct &acc);

bool transferMoney(BankAccountStruct &from, BankAccountStruct &to, double value);

#endif /* BANKUTIL_H_ */
