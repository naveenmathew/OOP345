/*
Name: Naveen Mathew
Mail: nmathew11@myseneca.ca
ID: 164646218
Date : 10-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/

#include <iomanip>
#include "Book.h"


namespace seneca {

	const std::string& Book::title() const
	{
		return this->B_title;
	}

	const std::string& Book::country() const
	{
		return this->B_country;
	}

	const size_t& Book::year() const
	{
		return this->B_year;
	}

	double& Book::price()
	{
		return B_price;
	}

    Book::Book(const std::string& strBook)
        : B_author(""), B_title(""), B_country(""), B_year(0), B_price(0.0), B_desc("")
    {
        size_t pos1 = strBook.find(',');
        size_t pos2 = strBook.find(',', pos1 + 1);
        size_t pos3 = strBook.find(',', pos2 + 1);
        size_t pos4 = strBook.find(',', pos3 + 1);
        size_t pos5 = strBook.find(',', pos4 + 1);

        std::string author_str = strBook.substr(0, pos1);
        std::string title_str = strBook.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string country_str = strBook.substr(pos2 + 1, pos3 - pos2 - 1);
        std::string price_str = strBook.substr(pos3 + 1, pos4 - pos3 - 1);
        std::string year_str = strBook.substr(pos4 + 1, pos5 - pos4 - 1);
        std::string desc_str = strBook.substr(pos5 + 1);


        author_str.erase(0, author_str.find_first_not_of(' '));
        author_str.erase(author_str.find_last_not_of(' ') + 1);
        title_str.erase(0, title_str.find_first_not_of(' '));
        title_str.erase(title_str.find_last_not_of(' ') + 1);
        country_str.erase(0, country_str.find_first_not_of(' '));
        country_str.erase(country_str.find_last_not_of(' ') + 1);
        price_str.erase(0, price_str.find_first_not_of(' '));
        price_str.erase(price_str.find_last_not_of(' ') + 1);
        year_str.erase(0, year_str.find_first_not_of(' '));
        year_str.erase(year_str.find_last_not_of(' ') + 1);
        desc_str.erase(0, desc_str.find_first_not_of(' '));
        desc_str.erase(desc_str.find_last_not_of(' ') + 1);

        B_author = author_str;
        B_title = title_str;
        B_country = country_str;
        B_price = std::stod(price_str);
        B_year = std::stoi(year_str);
        B_desc = desc_str;
    }


    std::ostream& operator<<(std::ostream& os, const Book& book) {

        os << std::right << std::setw(20) << book.B_author << " | ";
        os << std::right << std::setw(22) << book.B_title << " | ";
        os << std::right << std::setw(5) << book.B_country << " | ";
        os << std::right << std::setw(4) << book.B_year << " | ";
        os << std::fixed << std::setprecision(2) << std::setw(6) << book.B_price << " | ";
        os << book.B_desc << std::endl;
        return os;
    }









}