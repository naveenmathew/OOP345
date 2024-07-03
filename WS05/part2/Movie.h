/*
Name: Naveen Mathew
Mail: nmathew11@myseneca.ca
ID: 164646218
Date : 10-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H


#include <string>
#include <ostream>
#include <iomanip>
#include <unordered_map>

namespace seneca {

	class Movie {

		std::string M_title{};
		size_t M_year{};;
		std::string M_desc{};


	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
	

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(M_title);
			spellChecker(M_desc);
		}


		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);



	};



}

#endif
