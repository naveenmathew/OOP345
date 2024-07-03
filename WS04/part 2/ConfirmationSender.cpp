/*
Name:Naveen Mathew
StudentID : 1646464218
mail: nmathew11@myseneca.ca
Date: 09-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/
#include "ConfirmationSender.h"
#include <iostream>

namespace seneca {

    ConfirmationSender::ConfirmationSender() : m_reservations(nullptr), m_count(0) {}

    ConfirmationSender::~ConfirmationSender() {
        delete[] m_reservations;
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& other) : m_reservations(nullptr), m_count(0) {
        *this = other;
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other) {
        if (this != &other) {
            delete[] m_reservations;

            m_count = other.m_count;
            m_reservations = new const Reservation*[m_count];
            for (size_t i = 0; i < m_count; ++i) {
                m_reservations[i] = other.m_reservations[i];
            }
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& other) noexcept : m_reservations(other.m_reservations), m_count(other.m_count) {
        other.m_reservations = nullptr;
        other.m_count = 0;
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept {
        if (this != &other) {
            delete[] m_reservations;

            m_reservations = other.m_reservations;
            m_count = other.m_count;

            other.m_reservations = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        for (size_t i = 0; i < m_count; i++) {
            if (m_reservations[i] == &res) {
                return *this;
            }
        }

        const Reservation** temp = new const Reservation*[m_count + 1];
        for (size_t i = 0; i < m_count; ++i) {
            temp[i] = m_reservations[i];
        }
        temp[m_count] = &res;

        delete[] m_reservations;
        m_reservations = temp;
        m_count++;

        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        for (size_t i = 0; i < m_count; i++) {
            if (m_reservations[i] == &res) {
                m_reservations[i] = nullptr;
                break;
            }
        }

        size_t newCount = 0;
        for (size_t i = 0; i < m_count; i++) {
            if (m_reservations[i] != nullptr) {
                newCount++;
            }
        }

        const Reservation** temp = new const Reservation*[newCount];
        size_t index = 0;
        for (size_t i = 0; i < m_count; i++) {
            if (m_reservations[i] != nullptr) {
                temp[index++] = m_reservations[i];
            }
        }

        delete[] m_reservations;
        m_reservations = temp;
        m_count = newCount;

        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender) {
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;

        if (sender.m_count == 0) {
            os << "There are no confirmations to send!" << std::endl;
        } else {
            for (size_t i = 0; i < sender.m_count; i++) {
                os << *sender.m_reservations[i];
            }
        }

        os << "--------------------------" << std::endl;

        return os;
    }

}
