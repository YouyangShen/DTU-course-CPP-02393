#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <string>

using namespace std;

class BankAccount {
private:
	int number;
	string owner;
	double balance;

public:
    // Constructor
    BankAccount(int no, string own, double bal);

    // Destructor
    ~BankAccount();

    void print() const;
    bool transferMoney(BankAccount &to, double value);
    bool transferMoneyBAD(BankAccount to, double value);
};

#endif /* BANKACCOUNT_H_ */
