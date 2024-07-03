/*
Name: Naveen Mathew
Mail: nmathew11@myseneca.ca
ID: 164646218
Date : 10-06-2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/

#include "SpellChecker.h"


namespace seneca {

    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw ("Bad file name!");
        }

        std::string line;
        int index = 0;
        while (std::getline(file, line) && index < NUM_WORDS) {
            std::istringstream iss(line);
            iss >> m_badWords[index] >> m_goodWords[index];
            m_replacementCounts.push_back(0);
            ++index;
        }

        file.close();
    }

    void SpellChecker::operator()(std::string& text) {
        for (int i = 0; i < NUM_WORDS; ++i) {
            size_t pos = 0;
            while ((pos = text.find(m_badWords[i], pos)) != std::string::npos) {
                text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                m_replacementCounts[i]++;
                pos += m_goodWords[i].length();
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const {
        out << "Spellchecker Statistics" << std::endl;
        for (int i = 0; i < NUM_WORDS; ++i) {
            out << std::right << std::setw(15) << m_badWords[i] << ": " << m_replacementCounts[i] << " replacements" << std::endl;
        }
    }

}