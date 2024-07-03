/*
Name: Naveen Mathew
Mail: nmathew11@myseneca.ca
ID: 164646218
Date : 19-05-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
 #define _CRT_SECURE_NO_WARNINGS
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
        m_descFood= nullptr;
        price = 0.0;
        ds = false;
    }

   FoodOrder::FoodOrder(const FoodOrder& other)
    : m_descFood(nullptr), price(other.price), ds(other.ds) {
    std::strncpy(m_name, other.m_name, 11);
    m_name[10] = '\0'; 

    if (other.m_descFood) {
        m_descFood = new char[std::strlen(other.m_descFood) + 1];
        std::strcpy(m_descFood, other.m_descFood);
    }
}


seneca::FoodOrder& seneca::FoodOrder::operator=(const FoodOrder& other) {
    if (this != &other) {
      
        delete[] m_descFood;
        m_descFood = nullptr;

        std::strncpy(m_name, other.m_name, 11);
        m_name[10] = '\0'; 
        price = other.price;
        ds = other.ds;

        if (other.m_descFood) {
            m_descFood = new char[std::strlen(other.m_descFood) + 1];
            std::strcpy(m_descFood, other.m_descFood);
        }
    }
    return *this;
}


    void FoodOrder::read(std::istream& in) {
        if (in.good()) {
            in.getline(m_name, 11, ',');
             char buffer[256];
        in.getline(buffer, 256, ',');
        delete[] m_descFood;
        m_descFood = new char[std::strlen(buffer) + 1];
        std::strcpy(m_descFood, buffer);

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
        if (m_name[0] == '\0') {
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

    FoodOrder::~FoodOrder() {
        delete[] m_descFood;
        m_descFood = nullptr;
    }

}
