

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {
class Book {
    std::string m_title{};
    unsigned m_numChapters{};
    unsigned m_numPages{};

   public:
    Book(){};
    Book(const std::string& title, unsigned nChapters, unsigned nPages);
    Book& operator=(const Book& book);
    bool operator<(const Book& book);
    bool operator>(const Book& book);

    // In completing Part 2, add here the missing
    // member prototypes that would be necessary for
    // OrderedCollection module code and tester module
    // w3_p2.cpp to manage Book-type object.
    //
    // Write the implementations of these functions
    // in Book.cpp file

    std::ostream& print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Book& bk);
}  // namespace sdds
#endif  // SDDS_BOOK_H