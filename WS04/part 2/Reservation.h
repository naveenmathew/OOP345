/*
Name:Naveen Mathew
StudentID : 1646464218
mail: nmathew11@myseneca.ca
Date: 09-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/
#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <string>
#include <iostream>

namespace seneca {

    class Reservation {
        char m_reservationId[11];
        std::string m_name;
        std::string m_email;
        int m_partySize;
        int m_day;
        int m_hour;

    public:
        Reservation();
        Reservation(const std::string& res);
        void update(int day, int time);

        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };

}

#endif
