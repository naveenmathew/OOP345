/*
Name: Naveen Mathew
Mail: nmathew11@myseneca.ca
ID: 164646218
Date : 10-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H


#include <string>

namespace seneca{

	class Book {

		std::string B_author{};
		std::string B_title{};
		std::string B_country{};
		size_t B_year{};
		double B_price{};
		std::string B_desc{};


	public:
		Book() {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price(); 
		Book(const std::string& strBook);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(B_desc);
		}

		friend std::ostream& operator<<(std::ostream& os, const Book& B);



	};

}

#endif