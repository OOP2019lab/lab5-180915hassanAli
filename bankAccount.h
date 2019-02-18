#pragma once

#include <string>
using namespace std;

class bankAccount {
private:
	string UserName;
	int UserID;

	float balance;
	float balanceLimit;

	float * transactions;
	int TransCap;
	int TransCount;

	void AddTransaction(int Amount);

	void bankAccount::increaseTransCapacity();

public:
	bankAccount(string Name,int ID);

	void printAccount();

	void withDraw(float Amount);

	void deposit(float Amount);

	~bankAccount();
};