/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>

namespace sdds {
class Utilities {
    size_t m_widthField{1};
    static char m_delimiter;

   public:
    // Member functions
    void setFieldWidth(size_t newWidth);
    size_t getFieldWidth() const;
    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    // Class (static) functions
    static void setDelimiter(char newDelimiter);
    static char getDelimiter();
};
}  // namespace sdds
#endif  // SDDS_UTILITIES_H