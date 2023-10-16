/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>

namespace sdds {

class Movie {
    std::string m_title{};
    std::string m_description{};
    size_t m_year{};

   public:
    Movie(){};
    Movie(const std::string& strMovie);
    const std::string& title() const;
    std::string getNextToken(const std::string& str, size_t& start, char delimiter);
    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    template <typename T>
    void fixSpelling(T& spellChecker) {
        spellChecker(m_title);
        spellChecker(m_description);
    }
};

std::ostream& operator<<(std::ostream& os, const Movie& movie);
}  // namespace sdds
#endif  // SDDS_MOVIE_H