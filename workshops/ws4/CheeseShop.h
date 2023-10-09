/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include <string>

#include "Cheese.h"

namespace sdds {
class CheeseShop {
    const Cheese** m_cheeses{};
    std::string m_shopName{"No Name"};
    int m_numOfCheeses{};
    
    void setDefault();

   public:
    CheeseShop(const CheeseShop& cheeseShop);
    CheeseShop& operator=(const CheeseShop& cheeseShop);
    ~CheeseShop();
    CheeseShop(CheeseShop&& cheeseShop);
    CheeseShop& operator=(CheeseShop&& cheeseShop);
    CheeseShop(){};
    CheeseShop(const std::string&);
    CheeseShop& addCheese(const Cheese& cheese);
    int getNumOfCheeses() const;
    std::string getShopName() const;
    const Cheese* operator[](int index) const;
    friend std::ostream& operator<<(std::ostream& os, const CheeseShop& cheeseShop);
};

std::ostream& operator<<(std::ostream& os, const CheeseShop& cheeseShop);
}  // namespace sdds
#endif  // SDDS_CHEESESHOP_H