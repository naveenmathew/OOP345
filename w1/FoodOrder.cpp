/*
Name: Naveen Mathew
Mail: nmathew11@myseneca.ca
ID: 164646218
Date : 19-05-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "FoodOrder.h"

namespace seneca {
    double g_taxrate = 0.00;
    double g_dailydiscount = 0.00;

    FoodOrder::FoodOrder() {
        m_name[0] = '\0';
        m_descFood[0] = '\0';
        price = 0.0;
        ds = false;
    }

    void FoodOrder::read(std::istream& in) {
        if (in.good()) {
            in.getline(m_name, 11, ',');
            in.getline(m_descFood, 26, ',');
            in >> price;
            in.ignore();
            char dailySpecial;
            in >> dailySpecial;
            in.ignore();
            ds = (dailySpecial == 'Y');
        }
    }

    void FoodOrder::display() const {
        static int counter = 1;

        std::cout << std::left << std::setw(2) << counter << ". ";
        if (std::strlen(m_name) == 0) {
            std::cout << "No Order\n";
        } else {
            double priceWithTax = price * (1 + g_taxrate);
            std::cout << std::left << std::setw(10) << m_name << "|"
                      << std::left << std::setw(25) << m_descFood << "|"
                      << std::left << std::setw(12) << std::fixed << std::setprecision(2)
                      << priceWithTax << "|";
            if (ds) {
                std::cout << std::right << std::setw(13)
                          << priceWithTax - g_dailydiscount;
            }
            std::cout << "\n";
        }
        counter++;
    }
}
