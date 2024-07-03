/*
Name: Naveen Mathew
Mail: nmathew11@myseneca.ca
ID: 164646218
Date : 10-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/

#include "Movie.h"



namespace seneca {
	const std::string& seneca::Movie::title() const
	{
		return this->M_title;
	}

	Movie::Movie(const std::string& strMovie)
        :M_title(""), M_year(0), M_desc("")
    {
        size_t pos1 = strMovie.find(',');
        size_t pos2 = strMovie.find(',', pos1 + 1);



        std::string title_str = strMovie.substr(0, pos1);
        std::string year_str = strMovie.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string desc_str = strMovie.substr(pos2 + 1);
  
       
        title_str.erase(0, title_str.find_first_not_of(' '));
        title_str.erase(title_str.find_last_not_of(' ') + 1);
        year_str.erase(0, year_str.find_first_not_of(' '));
        year_str.erase(year_str.find_last_not_of(' ') + 1);
        desc_str.erase(0, desc_str.find_first_not_of(' '));
        desc_str.erase(desc_str.find_last_not_of(' ') + 1);

       
        M_title = title_str;
        M_year = std::stoi(year_str);
        M_desc = desc_str;
    }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os << std::setw(40) << movie.M_title << " | " << std::setw(4) << movie.M_year << " | " << movie.M_desc << std::endl;
        return os;
    }


}