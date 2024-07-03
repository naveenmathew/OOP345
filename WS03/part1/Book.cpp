#define CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"


namespace seneca{

    Book::Book() : m_title{""}, m_numChapters{0}, m_numPages{0} {}

    Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
        : m_title{title}, m_numChapters{nChapters}, m_numPages{nPages} {}

    bool Book::isValid() const {
        return !m_title.empty() && m_numChapters > 0 && m_numPages > 0;
    }

    std::ostream& Book::print(std::ostream& os) const {
        if (isValid()) {
            os << std::right << std::setw(56)
   << m_title + "," + std::to_string(m_numChapters) + "," + std::to_string(m_numPages) << " | " <<"("
   << std::left << std::setw(6)
   << std::fixed << std::setprecision(6)
   << static_cast<double>(m_numPages) / m_numChapters<<")    ";
        } else {
            os << "| Invalid book data";
        }
        return os;
    }

    const std::string& Book::getTitle() const {
        return m_title;
    }

    unsigned Book::getNumChapters() const {
        return m_numChapters;
    }

    unsigned Book::getNumPages() const {
        return m_numPages;
    }

    std::ostream& operator<<(std::ostream& os, const Book& newbook) {
        return newbook.print(os);
    }
    
}