/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds {
class Station {
    int m_stationID{};
    std::string m_itemName{};
    std::string m_description{};
    size_t m_serialNum{};
    size_t m_numOfItems{};
    static size_t m_widthField;
    static size_t id_generator;

   public:
    Station(){};
    Station(const std::string& line);
    const std::string& getItemName() const;
    size_t getNextSerialNumber();
    size_t getQuantity() const;
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
};
}  // namespace sdds
#endif  // SDDS_STATION_H