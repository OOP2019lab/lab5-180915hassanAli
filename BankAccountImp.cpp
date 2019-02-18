#include "bankAccount.h"

#include <iostream>
#include <cmath>

using namespace std;

//constructor
bankAccount::bankAccount(string Name,int ID){
	UserName=Name;
	UserID=ID;

	transactions=new float[10];

	balanceLimit=200000;

	balance=0;
	TransCap=10;
	TransCount=0;
}

//prints account information
void bankAccount::printAccount(){
	cout<<"User Name: "<<UserName<<endl;
	cout<<"User ID: "<<UserID<<endl;
	cout<<"Current Balance: "<<balance<<endl;

	//prints transaction informtion
	cout<<"Number of transactions: "<<TransCount<<endl;
	if (TransCount==0){
		cout<<"User has made no transactions";
	}
	else{
		cout<<"Transactions are: ";
		for (int c=0;c<TransCount;++c){
			cout<<transactions[c]<<",";
		}
	}
}

//withdraws passed amount
void bankAccount::withDraw(float Amount){
	//ensures amount is positive
	Amount=abs(Amount);

	if (Amount<=balance){
		cout<<"Transactions successful "<<endl;

		balance=balance-Amount;

		AddTransaction(-1*Amount);
	}
	else{
		cout<<"Transactions unsuccessful "<<endl;
	}

}

//deposits passed amount
void bankAccount::deposit(float Amount){

	Amount=abs(Amount);
	//ensures balance does not exceed limit
	if ((balance+Amount)<=balanceLimit){
		balance=balance+Amount;

		cout<<"Transactions successful "<<endl;

		AddTransaction(Amount);
	}
	else{
		cout<<"Transactions unsuccessful "<<endl;
	}
}

//add transaction to array
void bankAccount::AddTransaction(int Amount){
	//checks if array has memory
	if (TransCount<TransCap){
		transactions[TransCount]=Amount;
		++TransCount;
	}
	//if array has no memory
	else{
		increaseTransCapacity();

		transactions[TransCount]=Amount;
		++TransCount;
	}
}

//doubles capacity of transaction array
void bankAccount::increaseTransCapacity(){
	float * temp=new float[2*TransCap];
		for (int c=0;c<TransCap;++c){
			temp[c]=transactions[c];
		}
		delete[] transactions;
		transactions=temp;
		TransCap=TransCap*2;
}

//destructor
bankAccount::~bankAccount(){
	delete[] transactions;
	transactions=nullptr;
}
