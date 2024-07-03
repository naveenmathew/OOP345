/*
Name: Naveen Mathew
Mail: nmathew11@myseneca.ca
ID: 164646218
Date : 10-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <string>
#include <stdexcept>

namespace seneca {

    template<typename T>
    class Collection {
        std::string m_name;
        T* m_items;
        size_t m_size;
        void (*m_observer)(const Collection<T>&, const T&);

    public:
        Collection(const std::string& name)
            : m_name(name), m_items(nullptr), m_size(0), m_observer(nullptr) {}

        ~Collection() {
            delete[] m_items;
        }

        Collection(const Collection& other) = delete;
        Collection& operator=(const Collection& other) = delete;

        const std::string& name() const {
            return m_name;
        }

        size_t size() const {
            return m_size;
        }

        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            m_observer = observer;
        }

        Collection<T>& operator+=(const T& item) {
            for (size_t i = 0; i < m_size; ++i) {
                if (m_items[i].title() == item.title()) {
                    return *this; // Item already exists, do nothing
                }
            }

            T* temp = new T[m_size + 1];
            for (size_t i = 0; i < m_size; ++i) {
                temp[i] = m_items[i];
            }
            temp[m_size++] = item;

            delete[] m_items;
            m_items = temp;

            if (m_observer) {
                m_observer(*this, item);
            }

            return *this;
        }

        T& operator[](size_t idx) const {
            if (idx >= m_size) {
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
            }
            return m_items[idx];
        }

        T* operator[](const std::string& title) const {
            for (size_t i = 0; i < m_size; ++i) {
                if (m_items[i].title() == title) {
                    return &m_items[i];
                }
            }
            return nullptr;
        }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
        for (size_t i = 0; i < collection.size(); ++i) {
            os << collection[i];
        }
        return os;
    }

}

#endif
