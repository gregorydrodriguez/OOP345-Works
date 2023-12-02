/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>

#include "Station.h"

namespace sdds {
struct Item {
    std::string m_itemName{};
    size_t m_serialNumber{0};
    bool m_isFilled{false};

    Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
    std::string m_name{};
    std::string m_product{};
    size_t m_cntItem{};
    Item** m_listItem{};

    static size_t m_widthField;
    CustomerOrder& operator=(const CustomerOrder&) = delete;

   public:
    CustomerOrder(const CustomerOrder& order);
    ~CustomerOrder();
    CustomerOrder();
    CustomerOrder(const std::string& order);
    CustomerOrder(CustomerOrder&& src) noexcept;
    CustomerOrder& operator=(CustomerOrder&& src) noexcept;
    bool isOrderFilled() const;
    bool isItemFilled(const std::string& itemName) const;
    void fillItem(Station& station, std::ostream& os);
    void display(std::ostream& os) const;
};
}  // namespace sdds
#endif  // SDDS_CUSTOMERORDER_H