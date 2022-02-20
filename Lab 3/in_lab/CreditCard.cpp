#include <iostream>
#include <cstring>
#include "CreditCard.h"

using namespace std;
namespace sict {
    
    CreditCard c = nullptr;
    c = new CreditCard;

    void name(const char* cardHolderName[]){
        c.m_cardHolderName = cardHolderName;
    }
    void initialize(unsigned long long creditCardNumber,int instCode,int expiryYear,int expiryMonth,int numberInTheBack){
        c.m_cardNumber = creditCardNumber;
        c.m_institutionCode = instCode;
        c.m_expiryYear = expiryYear;
        c.m_expiryMonth = expiryMonth;
        c.m_numberInTheBack = numberInTheBack;
    }
	void write() const{
        bool valid = isValid();
        if(valid == true){
            cout << "Cardholder: " << c.m_cardHolderName << endl;
            cout << "Card Number: " << c.m_cardNumber << endl;
            cout << "Institution: " << c.m_institutionCode << endl;
            cout << "Expires: " << c.m_expiryMonth << "/" << c.m_expiryYear << endl;
            cout << "Number at the back: " << c.m_numberInTheBack;
        }
    }
	bool isValid() const{
        if((c.m_cardHolderName.length) > 1 && 
        (c.m_cardNumber > MIN_CARD_NUMBER && c.m_cardNumber < MAX_CARD_NUMBER) && 
        (c.m_institutionCode > MIN_INST_NUMBER && c.m_institutionCode < MAX_INST_NUMBER) && 
        (c.m_expiryYear > MIN_EXP_YEAR && c.m_expiryYear < MAX_EXP_YEAR) &&
        (c.m_expiryMonth >= 1 && c.m_expiryMonth <= 12) &&
        (c.m_numberInTheBack >= 0 && c.m_numberInTheBack < 1000)){
            return true;
        }else{
            return false;
        }

    }
    delete[] c;
    c = nullptr;

}
