#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <string>
#include <iostream>
#include <iomanip>

namespace seneca {
    class Reservation {
    private:
        std::string reservationId;
        std::string name;
        std::string email;
        int numPeople;
        int day;
        int hour;

    public:
        Reservation();
        Reservation(const std::string& reservationId, const std::string& name, const std::string& email, int numPeople, int day, int hour)
            : reservationId(reservationId), name(name), email(email), numPeople(numPeople), day(day), hour(hour) {}
        Reservation(const std::string& res);

        std::string getReservationId() const {
            return reservationId;
        }

        std::string getName() const {
            return name;
        }

        std::string getEmail() const {
            return email;
        }

        int getNumPeople() const {
            return numPeople;
        }

        int getDay() const {
            return day;
        }

        int getHour() const {
            return hour;
        }

        void update(int newDay, int newHour);

        friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);

        ~Reservation(){};
    };
}

#endif // SENECA_RESERVATION_H