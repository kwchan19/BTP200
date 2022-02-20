//TODO: add header guards here
#ifndef PASSENGER_H
#define PASSENGER_H
// TODO: holiday namespace here
namespace holiday{
    // TODO: declare the class Passenger here
    class Passenger{
        char m_name[32];
        char m_destination[32];
        int m_departureYear;
        int m_departureMonth;
        int m_departureDay;
    public:
        //Passenger::~Passenger();
	    //Passenger::~Passenger(char passengerName, char destinationJourney);
        void display(bool onlyNames = false) const;
        bool canTravelWith(const Passenger&) const;
        bool isEmpty() const;
        Passenger();
        Passenger(char passengerName, char destinationJourney);

        // TODO: add the class the attributes,
        //       the member function already provided,
        //       and the member functions that you must implement
    }
}
#endif