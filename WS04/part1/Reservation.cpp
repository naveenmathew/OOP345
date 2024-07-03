#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Reservation.h"



namespace seneca{
Reservation::Reservation() {} ;

Reservation::Reservation(const std::string& res) {
        std::ifstream file(res);
        std::string token;

        // Extract reservationId
        std::getline(file, token, ':');
        reservationId = token.substr(0, 10);

        // Extract name
        std::getline(file, token, ',');
        name = token.substr(0, 20);

        // Extract email
        std::getline(file, token, ',');
        email = token.substr(0, 20);

        // Extract numPeople
        std::getline(file, token, ',');
        numPeople = std::stoi(token);

        // Extract day
        std::getline(file, token, ',');
        day = std::stoi(token);

        // Extract hour
        std::getline(file, token);
        hour = std::stoi(token);
    }

    void Reservation::update(int newDay, int newHour) {
        day = newDay;
        hour = newHour;
    }

     std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
        std::string meal;

        if (reservation.hour >= 6 && reservation.hour < 9) {
            meal = "Breakfast";
        } else if (reservation.hour >= 11 && reservation.hour < 15) {
            meal = "Lunch";
        } else if (reservation.hour >= 17 && reservation.hour < 21) {
            meal = "Dinner";
        } else {
            meal = "Drinks";
        }

        os << std::right << std::setw(10) << reservation.reservationId << ": "
           << std::right << std::setw(20) << reservation.name << " <"
           << std::left << std::setw(20) << reservation.email << ">    "
           << meal << " on day " << reservation.day << " @ " << reservation.hour << ":00 for ";

        if (reservation.numPeople == 1) {
            os << "1 person";
        } else {
            os << reservation.numPeople << " people";
        }

        os << std::endl;

        return os;
    }



}