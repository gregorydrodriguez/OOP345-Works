/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {
class Book {
    std::string m_author{};
    std::string m_title{};
    std::string m_country{};
    std::string m_description{};
    size_t m_year{};
    double m_price{};

   public:
    // ~Book();
    Book(){};
    Book(const std::string& strBook);
    // Book(const Book& book);
    // Book& operator=(const Book& book);
    // Book(Book&& book);
    // Book& operator=(Book&& book);
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();
    void setPrice(double price);
    std::string getNextToken(const std::string& str, size_t& start, char delimiter);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

std::ostream& operator<<(std::ostream& os, const Book& book);
}  // namespace sdds
#endif  // SDDS_BOOK_H