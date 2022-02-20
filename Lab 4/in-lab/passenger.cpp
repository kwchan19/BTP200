// TODO: add your headers here
#include <iostream>
#include <string.h>
#include "passenger.h"

using namespace std;
namespace std{

// TODO: add the namespaces that you will be using here

// TODO: holiday namespace here

    // TODO: add the default constructor here

    // TODO: add the constructor with 2 parameters here

    // TODO: add the canTravelWith(...) function here

    // TODO: add the isEmpty() function here

    // below is the member function already provided
    // TODO: read it and understand how it accomplishes its task
	void Passenger::display(bool nameOnly) const
	{
		if (false == this->isEmpty())
		{
			cout << this->m_name;
			if (false == nameOnly)
			{
				cout << " will travel to " << this->m_destination << ". "
				     << "The journey will start on "
				     << this->m_departureYear << "-"
					 << this->m_departureMonth << "-"
					 << this->m_departureDay
				     << "." << endl;
			}
		}
		else
		{
			cout << "Invalid passenger!" << endl;
		}
	}
	Passenger::Passenger()
	{
		m_name = "";
        m_destination = "";
        m_departureYear = 0;
        m_departureMonth = 0;
        m_departureDay = 0;
	}

	Passenger::Passenger(char passengerName, char destinationJourney)
	{
		if(isEmpty() == false){
			strcpy(m_name,passengerName);
			strcpy(m_destination, destinationJourney);
			m_departureYear = 2017;
			m_departureMonth = 7;
			m_departureDay = 1;
		}
	}
	/*Passenger::~Passenger(){

	}
	Passenger::~Passenger(char passengerName, char destinationJourney){

	}*/

	bool Passenger::isEmpty() const
	{
		if(!passengerName.empty() && !destinationJourney.empty()){
			return false;
		}else{
			return true;
		}
	}

	bool Passenger::canTravelWith(const Passenger&) const
	{
		if(m_destination == Passenger.m_destination){
			return true;
		}else{
			return false;
		}
	}
}