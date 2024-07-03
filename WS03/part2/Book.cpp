/*
Name:Naveen Mathew
StudentID : 1646464218
mail: nmathew11@myseneca.ca
Date: 02-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/

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

    std::string Book::getTitle() const {
    return m_title;
    }

    unsigned Book::getChapters() const {
     return m_numChapters;
    }

    unsigned Book::getPages() const {
    return m_numPages;
   }
   double Book::pagesPerChapter() const
   {
         return static_cast<double>(m_numPages) / m_numChapters;
   }
   std::ostream &operator<<(std::ostream &os, const Book &newbook)
   {
       return newbook.print(os);
   }

     //p2

    bool Book::operator==(const Book& other) const {
        return m_title == other.m_title && m_numChapters == other.m_numChapters && m_numPages == other.m_numPages;
    }

    bool Book::operator!=(const Book& other) const {
        return !(*this == other);
    }

    bool Book::operator<(const Book& other) const {
        return this->pagesPerChapter() < other.pagesPerChapter();
    }

    bool Book::operator>(const Book& other) const {
        return this->pagesPerChapter() > other.pagesPerChapter();
    }
}
    
