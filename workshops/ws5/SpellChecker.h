/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>

const size_t MAX_WORDS = 6;

namespace sdds {
class SpellChecker {
    std::string m_badWords[MAX_WORDS]{};
    std::string m_goodWords[MAX_WORDS]{};
    size_t m_replacementCounts[MAX_WORDS]{};

   public:
    SpellChecker(const char* filename);
    void operator()(std::string& text);
    void showStatistics(std::ostream& out) const;
    void incReplacements(size_t index);
};
}  // namespace sdds
#endif  // SDDS_SPELLCHECKER_H