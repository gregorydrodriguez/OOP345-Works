/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Cheese.h"

#include <iomanip>
#include <iostream>
#include <string>

namespace sdds {

Cheese::Cheese(const Cheese& cheese) {
    m_name = cheese.m_name;
    m_weight = cheese.m_weight;
    m_price = cheese.m_price;
    m_features = cheese.m_features;
}

Cheese& Cheese::operator=(Cheese& cheese) {
    if (this == &cheese) {
        m_name = cheese.m_name;
        m_weight = cheese.m_weight;
        m_price = cheese.m_price;
        m_features = cheese.m_features;
    }
    return *this;
}

Cheese::Cheese(const std::string& str) {
    // Current position in str
    size_t start = 0;
    // Tokenize name
    m_name = getNextToken(str, start);
    // Tokenize weight
    m_weight = std::stoul(getNextToken(str, start));
    // Tokenize price
    m_price = std::stod(getNextToken(str, start));
    // Tokenize features
    while (start != std::string::npos) {
        m_features += getNextToken(str, start);
        if (start != std::string::npos) {
            m_features += ' ';
        }
    }
}

std::string Cheese::getNextToken(const std::string& str, size_t& start) {
    if (start == std::string::npos) {
        std::cout << "THIS SHOULD NOT PRINT" << std::endl;
        return "ERROR";
    }
    const size_t end = str.find(',', start);
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

Cheese Cheese::slice(size_t weight) {
    Cheese cheese;
    if (m_weight >= weight) {
        cheese = *this;
        cheese.m_weight = weight;
        m_weight -= weight;
        return cheese;
    }
    return cheese;
}

std::string Cheese::getName() const {
    return m_name;
}

std::string Cheese::getFeatures() const {
    return m_features;
}

unsigned int Cheese::getWeight() const {
    return m_weight;
}

double Cheese::getPrice() const {
    return m_price;
}

std::ostream& operator<<(std::ostream& os, const Cheese& cheese) {
    os << "|" << std::left << std::setw(21) << cheese.getName();
    os << "|" << std::setw(5) << cheese.getWeight();
    os << "|" << std::fixed << std::setw(5) << std::setprecision(2) << cheese.getPrice();
    os << "|" << std::right << std::setw(33) << cheese.getFeatures();
    os << " |" << std::endl;
    return os;
}
}  // namespace sdds