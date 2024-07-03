/*
Name:Naveen Mathew
StudentID : 1646464218
mail: nmathew11@myseneca.ca
Date: 02-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H


namespace seneca{
    class Book
{
	std::string m_title{};
	unsigned m_numChapters{};
	unsigned m_numPages{};
public:
    Book();
    Book(const std::string& title, unsigned nChapters, unsigned nPages);

    std::ostream& print(std::ostream& os) const;
    bool isValid() const;
       std::string getTitle() const;
    unsigned getChapters() const;
    unsigned getPages() const;
	double pagesPerChapter() const;
    bool operator==(const Book& other) const;
    bool operator!=(const Book& other) const;
    bool operator<(const Book& other) const;
    bool operator>(const Book& other) const;
};
std::ostream& operator<<(std::ostream& os, const Book& bk);


}

#endif