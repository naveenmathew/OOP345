/*
Name:Naveen Mathew
StudentID : 1646464218
mail: nmathew11@myseneca.ca
Date: 02-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>

namespace seneca {
    template <typename T, unsigned C>
    class Collection {
        T m_items[C];
        unsigned m_size{0};

        static T m_smallestItem;
        static T m_largestItem;

    protected:
        void setSmallestItem(const T& item) {
            if (m_size == 1 || item < m_smallestItem) {
                m_smallestItem = item;
            }
        }

        void setLargestItem(const T& item) {
            if (m_size == 1 || item > m_largestItem) {
                m_largestItem = item;
            }
        }
    protected:
               void incrSize() { ++m_size; }
        T& operator[](unsigned index) { return m_items[index]; }
        const T& operator[](unsigned index) const { return m_items[index]; }
    public:
        Collection() {
            m_smallestItem = T(); 
            m_largestItem = T();  
        }

        bool operator+=(const T& item) {
            if (m_size < C) {
                m_items[m_size++] = item;
                setSmallestItem(item);
                setLargestItem(item);
                return true;
            }
            return false;
        }

        unsigned size() const { return m_size; }
        unsigned capacity() const { return C; }

        void print(std::ostream& os) const {
            os << "[";
            for (unsigned i = 0; i < m_size; ++i) {
                os << std::setprecision(1)<<m_items[i];
                if (i < m_size - 1) {
                    os << ",";
                }
            }
            os << "]";
            os<<std::endl;
        }

        static T getSmallestItem() { return m_smallestItem; }
        static T getLargestItem() { return m_largestItem; }
    };

    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = T(); 

    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = T(); 
 template <>
    Book Collection<Book, 72>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 72>::m_largestItem = Book("", 10000, 1);

    template <>
   void Collection<Book, 10>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        for (unsigned i = 0; i < m_size; ++i) {
            os << "| " << std::setw(56) << std::right << m_items[i] << " |" << std::endl;
        }
        os << "| ---------------------------------------------------------------------------|" << std::endl;
    }

    template <>
    
    void Collection<Book, 72>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        for (unsigned i = 0; i < m_size; ++i) {
            os << "| " << std::setw(56) << std::right << std::setprecision(1) << m_items[i] << " |" << std::endl;
        }
        os << "| ---------------------------------------------------------------------------|" << std::endl;
    }
}

#endif
