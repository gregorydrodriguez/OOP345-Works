/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Utilities.h"

#include <iostream>

namespace sdds {
char Utilities::m_delimiter{};

void Utilities::setFieldWidth(size_t newWidth) {
    m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
    return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
    size_t delimiterPos = str.find(m_delimiter, next_pos);
    if (delimiterPos == next_pos) {
        more = false;
        throw std::invalid_argument("Delimiter found at next position.");
    }
    std::string token = str.substr(next_pos, delimiterPos - next_pos);
    next_pos = str.find(m_delimiter, next_pos) + 1;
    more = (delimiterPos != std::string::npos);
    token.erase(0, token.find_first_not_of(' '));
    token.erase(token.find_last_not_of(' ') + 1);
    if (m_widthField < token.length()) {
        m_widthField = token.length();
    }
    return token;
}

void Utilities::setDelimiter(char newDelimiter) {
    m_delimiter = newDelimiter;
}
char Utilities::getDelimiter() {
    return m_delimiter;
}
}  // namespace sdds