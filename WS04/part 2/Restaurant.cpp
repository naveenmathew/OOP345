/*
Name:Naveen Mathew
StudentID : 1646464218
mail: nmathew11@myseneca.ca
Date: 09-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/

#include "Restaurant.h"
#include <iostream>

namespace seneca {

    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) : m_reservations(nullptr), m_count(0) {
        if (reservations != nullptr && cnt > 0) {
            m_reservations = new Reservation*[cnt];
            for (size_t i = 0; i < cnt; i++) {
                m_reservations[i] = new Reservation(*reservations[i]);
            }
            m_count = cnt;
        }
    }

    Restaurant::~Restaurant() {
        for (size_t i = 0; i < m_count; i++) {
            delete m_reservations[i];
        }
        delete[] m_reservations;
    }

    Restaurant::Restaurant(const Restaurant& other) : m_reservations(nullptr), m_count(0) {
        *this = other;
    }

    Restaurant& Restaurant::operator=(const Restaurant& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_count; i++) {
                delete m_reservations[i];
            }
            delete[] m_reservations;

            m_count = other.m_count;
            m_reservations = new Reservation*[m_count];
            for (size_t i = 0; i < m_count; i++) {
                m_reservations[i] = new Reservation(*other.m_reservations[i]);
            }
        }
        return *this;
    }

    Restaurant::Restaurant(Restaurant&& other) noexcept : m_reservations(other.m_reservations), m_count(other.m_count) {
        other.m_reservations = nullptr;
        other.m_count = 0;
    }

    Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < m_count; i++) {
                delete m_reservations[i];
            }
            delete[] m_reservations;

            m_reservations = other.m_reservations;
            m_count = other.m_count;

            other.m_reservations = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    size_t Restaurant::size() const {
        return m_count;
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& res) {
        static int CALL_CNT = 0;
        CALL_CNT++;

        os << "--------------------------" << std::endl;
        os << "Fancy Restaurant (" << CALL_CNT << ")" << std::endl;
        os << "--------------------------" << std::endl;

        if (res.m_count == 0) {
            os << "This restaurant is empty!" << std::endl;
        } else {
            for (size_t i = 0; i < res.m_count; i++) {
                os << *res.m_reservations[i];
            }
        }

        os << "--------------------------" << std::endl;

        return os;
    }

}
