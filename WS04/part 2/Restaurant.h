/*
Name:Naveen Mathew
StudentID : 1646464218
mail: nmathew11@myseneca.ca
Date: 09-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/
#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H

#include "Reservation.h"

namespace seneca {

    class Restaurant {
        Reservation** m_reservations;
        size_t m_count;

    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        ~Restaurant();
        Restaurant(const Restaurant& other);
        Restaurant& operator=(const Restaurant& other);
        Restaurant(Restaurant&& other) noexcept;
        Restaurant& operator=(Restaurant&& other) noexcept;

        size_t size() const;

        friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
    };

}

#endif
