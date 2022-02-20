#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
	

	// credit (add) an amount to the account balance

	
	// debit (subtract) an amount from the account balance return bool 
	virtual bool Account::debit(double x){
		 if(x < this->balance){
			 this->balance = this->balance - x;
			 return true;
		 }else{
			 return false;
		 }
			 
	}

	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
	
}