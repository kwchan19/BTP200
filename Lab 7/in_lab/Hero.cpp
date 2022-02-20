#include <cstring>
#include <iostream>
#include "Hero.h"

using namespace std;

//////////////////////////////////////////////
// Default constructor
//
Hero::Hero ()
{
    this->m_name[0] = '\0';    
    this->m_attack = 0;
    this->m_maximumHealth = 0;
    this->m_health = 0;
}


///////////////////////////////////////////////////
// Constructor
// 
Hero::Hero (const char name[], unsigned maximumHealth, unsigned attack)
{
    strcpy(this->m_name,name);
    this->m_maximumHealth = maximumHealth;
    this->m_attack = attack;
}

/////////////////////////////////////////////////////////
// 
// Hero::display function
void Hero::display (ostream & out) const 
{
    if(this->m_name[0] != '\0'){
        cout << this->m_name << endl;
    }
}



/////////////////////////////////////////////////
// Hero::isEmpty ()
// return true if the Hero object is uninitialized
//
bool Hero::isEmpty () const 
{   
    if(this->m_name[0] = '\0' && this->m_attack = 0 && this->m_maximumHealth = 0 && this->m_health = 0){
        return true;
    }else{
        return false;
    }
}

/////////////////////////////////////////////////
// sets the Hero object's health back to full
//
void Hero::respawn() 
{
    this->m_health = this->m_maximumHealth;
}

