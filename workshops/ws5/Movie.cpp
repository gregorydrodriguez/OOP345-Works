/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Movie.h"

#include <iostream>
#include <iomanip>

namespace sdds {

Movie::Movie(const std::string& strMovie) {
    size_t start = 0;
    m_title = getNextToken(strMovie, start, ',');
    m_year = std::stod(getNextToken(strMovie, start, ','));
    m_description = getNextToken(strMovie, start, '\n');
}

const std::string& Movie::title() const {
    return m_title;
}

std::string Movie::getNextToken(const std::string& str, size_t& start, char delimiter) {
    if (start == std::string::npos) {
        std::cout << "THIS SHOULD NOT PRINT" << std::endl;
        return "ERROR";
    }
    const size_t end = str.find(delimiter, start);
    // Get token and update str postition reference
    std::string token;
    if (end == std::string::npos) {
        token = str.substr(start, std::string::npos);  // Until end of str
        start = std::string::npos;                     // Indicate last token
    } else {
        token = str.substr(start, end - start);
        start = end + 1;  // Start of next token
    }
    // Trim whitespace
    token.erase(0, token.find_first_not_of(' '));
    token.erase(token.find_last_not_of(' ') + 1);
    return token;
}

std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    os << std::right << std::setw(40) << movie.m_title << " | ";
    os << std::setw(4) << movie.m_year << " | ";
    os << movie.m_description << std::endl;
    return os;
}
}  // namespace sdds