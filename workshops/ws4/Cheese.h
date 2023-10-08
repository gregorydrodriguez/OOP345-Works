/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H

#include <iostream>
#include <string>

namespace sdds {
class Cheese {
    std::string m_name{"NaC"};
    unsigned int m_weight{};
    double m_price{};
    std::string m_features{};

    std::string getNextToken(const std::string& str, size_t& start);

   public:
    Cheese(){};
    Cheese(const std::string& str);
    Cheese slice(size_t weight);
    std::string getName() const;
    std::string getFeatures() const;
    unsigned int getWeight() const;
    double getPrice() const;
};

std::ostream& operator<<(std::ostream& os, const Cheese& cheese);
}  // namespace sdds
#endif  // SDDS_CHEESE_H