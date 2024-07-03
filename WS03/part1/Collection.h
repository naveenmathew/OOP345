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

    public:
        Collection() {
            m_smallestItem = T(); // Use default constructor
            m_largestItem = T();  // Use default constructor
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

    // Initialize static members
    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = T(); // Default initialize to T's default constructor

    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = T(); // Default initialize to T's default constructor
}

#endif
