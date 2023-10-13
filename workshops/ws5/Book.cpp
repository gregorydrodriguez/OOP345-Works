/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Book.h"

#include <iomanip>
#include <iostream>
#include <string>

namespace sdds {
// Book::~Book();
// Book::Book(const Book& book);
// Book& Book::operator=(const Book& book);
// Book::Book(Book&& book);
// Book& Book::operator=(Book&& book);

Book::Book(const std::string& strBook) {
    // Current position in str
    size_t start = 0;
    // Tokenize author
    m_author = getNextToken(strBook, start, ',');
    // Tokenize title
    m_title = getNextToken(strBook, start, ',');
    // Tokenize country
    m_country = getNextToken(strBook, start, ',');
    // Tokenize price
    m_price = std::stod(getNextToken(strBook, start, ','));
    // Tokenize year
    m_year = std::stoul(getNextToken(strBook, start, ','));
    // Tokenize description
    m_description = getNextToken(strBook, start, '\n');
}

std::string Book::getNextToken(const std::string& str, size_t& start, char delimiter) {
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

const std::string& Book::title() const {
    return m_title;
}

const std::string& Book::country() const {
    return m_country;
}

const size_t& Book::year() const {
    return m_year;
}

double& Book::price() {
    return m_price;
}

void Book::setPrice(double price) {
    m_price = price;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << std::right << std::setw(20) << book.m_author << " | ";
    os << std::right << std::setw(22) << book.m_title << " | ";
    os << std::right << std::setw(5) << book.m_country << " | ";
    os << std::right << std::setw(4) << book.m_year << " | ";
    os << std::right << std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | ";
    os << std::left << book.m_description << std::endl;
    return os;
}
}  // namespace sdds