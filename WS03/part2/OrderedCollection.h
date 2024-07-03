/*
Name:Naveen Mathew
StudentID : 1646464218
mail: nmathew11@myseneca.ca
Date: 02-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/

#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace seneca {
    template <typename T>
    class OrderedCollection : public Collection<T, 72> {
    public:
        bool operator+=(const T& item) {
            if (this->size() < this->capacity()) {
                unsigned i = 0;
                while (i < this->size() && !(item < this->operator[](i))) {
                    ++i;
                }
                for (unsigned j = this->size(); j > i; --j) {
                    this->operator[](j) = this->operator[](j - 1);
                }
                this->operator[](i) = item;
                this->incrSize();
                this->setSmallestItem(item);
                this->setLargestItem(item);
                return true;
            }
            return false;
        }
    };
}

#endif