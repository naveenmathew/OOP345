/*
Name: Naveen Mathew
Mail: nmathew11@myseneca.ca
ID: 164646218
Date : 19-05-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/

#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>

namespace seneca {
    extern double g_taxrate;
    extern double g_dailydiscount;

    class FoodOrder {
        char m_name[11];
        char m_descFood[26];
        double price;
        bool ds;

       

    public:
        FoodOrder();
        void read(std::istream& in);
        void display() const;

    };
}

#endif // SENECA_FOODORDER_H
