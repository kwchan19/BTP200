#include "Contact.h"
#include <string.h>

using namespace std;

namespace communication{
        void Contact::display() const
        {   
            if(isEmpty == true){
                cout << "Empty contact!" << endl;
            }else{
                cout << this->m_name << endl;
                for(int i = 0; i < this->m_noOfPhoneNumbers; i++){
                    cout << this->m_phoneNumbers[i] << endl;
                }
            }
        }
		// TODO: add the isEmpty function here
		bool Contact::isEmpty() const
        {
            if(m_name[0] == '\0' && m_phoneNumbers == 0 && m_noOfPhoneNumbers == 0){
                return true;
            }else{
                return false;
            }
        }
        Contact::Contact()
        {
            m_name[0] = '\0';
            m_phoneNumbers = 0;
            m_noOfPhoneNumbers = 0;
        }
		// TODO: add the constructor with parameters here
		Contact::Contact(const char* name, long long*` phone, int size)
        {
            int count = 0;
            for(int i = 0; i < size; i++){
                if(name != '\0' && (phone[i].length >= 11 || phone[i].length <= 12)){
                    count++;
                }
            }
            if(count == size){
                strcpy(m_name, name);
                for(int i = 0; i < size; i++){
                    m_phoneNumbers[i] = phone[i];
                }
                m_noOfPhoneNumbers = size;
            }
        }
		// TODO: add the destructor here
		Contact::~Contact()
        {
            return 0;
        }
}