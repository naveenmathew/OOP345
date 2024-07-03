/*
Name:Naveen Mathew
StudentID : 1646464218
mail: nmathew11@myseneca.ca
Date: 09-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/
#include "Reservation.h"
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstring>

namespace seneca {

    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        if (first == std::string::npos)
            return "";
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, last - first + 1);
    }

    Reservation::Reservation() : m_name{""}, m_email{""}, m_partySize{0}, m_day{0}, m_hour{0} {
        m_reservationId[0] = '\0';
    }

    Reservation::Reservation(const std::string& res) {
        std::string temp = res;

        temp = trim(temp);

        if (temp.empty() || temp[0] == '#') {
            m_reservationId[0] = '\0';
            return;
        }

        try {
            size_t start = 0;
            size_t end = temp.find(':');
            if (end == std::string::npos) throw std::invalid_argument("Missing ':' delimiter");
            std::string id = temp.substr(start, end - start);
            id = trim(id);
            strncpy(m_reservationId, id.c_str(), 10);
            m_reservationId[10] = '\0';

            start = end + 1;
            end = temp.find(',', start);
            if (end == std::string::npos) throw std::invalid_argument("Missing ',' delimiter after name");
            std::string name = temp.substr(start, end - start);
            m_name = trim(name);

            start = end + 1;
            end = temp.find(',', start);
            if (end == std::string::npos) throw std::invalid_argument("Missing ',' delimiter after email");
            std::string email = temp.substr(start, end - start);
            m_email = trim(email);

            start = end + 1;
            end = temp.find(',', start);
            if (end == std::string::npos) throw std::invalid_argument("Missing ',' delimiter after party size");
            std::string partySizeStr = temp.substr(start, end - start);
            partySizeStr = trim(partySizeStr);
            if (partySizeStr.empty()) throw std::invalid_argument("Empty party size");
            m_partySize = std::stoi(partySizeStr);

            start = end + 1;
            end = temp.find(',', start);
            if (end == std::string::npos) throw std::invalid_argument("Missing ',' delimiter after day");
            std::string dayStr = temp.substr(start, end - start);
            dayStr = trim(dayStr);
            if (dayStr.empty()) throw std::invalid_argument("Empty day");
            m_day = std::stoi(dayStr);

            start = end + 1;
            std::string hourStr = temp.substr(start);
            hourStr = trim(hourStr);
            if (hourStr.empty()) throw std::invalid_argument("Empty hour");
            m_hour = std::stoi(hourStr);

        } catch (const std::invalid_argument& e) {
            std::cerr << "Error parsing reservation string: '" << res << "'" << std::endl;
            std::cerr << "Exception: " << e.what() << std::endl;
            throw;
        } catch (const std::exception& e) {
            std::cerr << "Error parsing reservation string: '" << res << "'" << std::endl;
            std::cerr << "Exception: " << e.what() << std::endl;
            throw;
        }
    }

    void Reservation::update(int day, int time) {
        m_day = day;
        m_hour = time;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        if (res.m_reservationId[0] == '\0') {
            return os;
        }

        os << "Reservation " << std::right << std::setw(10) << res.m_reservationId << ": "
           << std::setw(20) << res.m_name;
        os << std::left << "  <" << std::setw(23) << (res.m_email + ">") << std::left;

        std::string meal;
        if (res.m_hour >= 6 && res.m_hour <= 9)
            meal = "Breakfast";
        else if (res.m_hour >= 11 && res.m_hour <= 15)
            meal = "Lunch";
        else if (res.m_hour >= 17 && res.m_hour <= 21)
            meal = "Dinner";
        else
            meal = "Drinks";

        os << meal << std::left << " on day " << res.m_day << " @ " << res.m_hour << ":00"
           << " for " << res.m_partySize << (res.m_partySize == 1 ? " person." : " people.") << std::endl;

        return os;
    }
}