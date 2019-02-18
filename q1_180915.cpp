#include <iostream>

#include "bankAccount.h"

using namespace std;

void main(){
	//create object
	bankAccount myAccount("John Doe",549002);

	//test withdraw and deposit
	myAccount.withDraw(2000);

	myAccount.deposit(250000);

	myAccount.deposit(50000);

	myAccount.withDraw(1000);

	//test increase in capacity for transactions
	for (int c=1;c<20;++c){
		myAccount.withDraw(c*10);
		myAccount.deposit(c*100);
	}

	myAccount.printAccount();

	system("pause");
}