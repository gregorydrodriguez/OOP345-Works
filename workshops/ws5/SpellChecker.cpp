/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "SpellChecker.h"

#include <fstream>
#include <iomanip>
#include <iostream>

namespace sdds {
SpellChecker::SpellChecker(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Bad file name!");
    } else {
        for (size_t i = 0; i < MAX_WORDS; i++) {
            file >> m_badWords[i];
            file >> m_goodWords[i];
            // std::cout << m_badWords[i] << m_goodWords[i] << std::endl;
        }
    }
    file.close();
}

void SpellChecker::operator()(std::string& text) {
    std::cout << "Spellchecker Statistics" << std::endl;
    for (size_t i = 0; i < MAX_WORDS; i++) {
        size_t pos = text.find(m_badWords[i]);
        while (pos != std::string::npos) {
            text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
            // m_replacementCounts[i]++ ???
            incReplacements(i);
            pos = text.find(m_badWords[i], pos + m_goodWords[i].length());
        }
    }
}

void SpellChecker::showStatistics(std::ostream& out) const {
    for (size_t i = 0; i < MAX_WORDS; i++) {
        out << std::setw(15) << std::right << m_badWords[i] << " " << m_replacementCounts[i] << " " << m_goodWords[i] << std::endl;
    }
}

void SpellChecker::incReplacements(size_t index) {
    m_replacementCounts[index]++;
}
}  // namespace sdds