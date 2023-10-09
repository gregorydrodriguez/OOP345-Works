/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include "Cheese.h"

namespace sdds {
class CheeseParty {
    const Cheese** m_pCheeses{};
    int m_numOfCheeses{};

    void setDefault();

   public:
    ~CheeseParty();
    CheeseParty(const CheeseParty& cheeseParty);
    CheeseParty& operator=(const CheeseParty& cheeseParty);
    CheeseParty(CheeseParty&& cheeseParty);
    CheeseParty& operator=(CheeseParty&& cheeseParty);
    CheeseParty(){};
    CheeseParty& addCheese(const Cheese& cheese);
    CheeseParty& removeCheese();
    int getNumOfCheeses() const;
    friend std::ostream& operator<<(std::ostream& os, const CheeseParty& cheeseParty);
};

std::ostream& operator<<(std::ostream& os, const CheeseParty& cheeseParty);
}  // namespace sdds
#endif  // SDDS_CHEESEPARTY_H