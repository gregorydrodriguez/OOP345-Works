/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "CheeseShop.h"

namespace sdds {

CheeseShop::CheeseShop(const CheeseShop& cheeseShop) {
    *this = cheeseShop;
}

CheeseShop& CheeseShop::operator=(const CheeseShop& cheeseShop) {
    if (this != &cheeseShop) {
        if (cheeseShop.m_cheeses != nullptr) {
            m_shopName = cheeseShop.m_shopName;
            m_numOfCheeses = cheeseShop.m_numOfCheeses;
            deleteCheeses();
            m_cheeses = new const Cheese*[m_numOfCheeses];
            for (int i = 0; i < m_numOfCheeses; i++) {
                m_cheeses[i] = cheeseShop.m_cheeses[i];
            }
        } else {
            m_cheeses = nullptr;
        }
    }
    return *this;
}

CheeseShop::~CheeseShop() {
    deleteCheeses();
}

void CheeseShop::deleteCheeses() {
    for (int i = 0; i < m_numOfCheeses; i++) {
        delete m_cheeses[i];
    }
    delete[] m_cheeses;
}

CheeseShop::CheeseShop(CheeseShop&& cheeseShop) {
    *this = cheeseShop;
    cheeseShop.setDefault();
}

CheeseShop& CheeseShop::operator=(CheeseShop&& cheeseShop) {
    if (this != &cheeseShop) {
        *this = cheeseShop;
        cheeseShop.setDefault();
    }
    return *this;
}

CheeseShop::CheeseShop(const std::string& name) {
    m_shopName = name;
}

void CheeseShop::setDefault() {
    m_cheeses = nullptr;
    m_shopName = "";
    m_numOfCheeses = 0;
}

CheeseShop& CheeseShop::addCheese(const Cheese& cheese) {
    const Cheese* copy = new const Cheese(cheese);
    const Cheese** newCheeses = new const Cheese*[m_numOfCheeses + 1];
    for (int i = 0; i < m_numOfCheeses; i++) {
        newCheeses[i] = m_cheeses[i];
    }
    delete[] m_cheeses;
    m_cheeses = newCheeses;
    m_cheeses[m_numOfCheeses] = copy;
    m_numOfCheeses++;
    return *this;
}

int CheeseShop::getNumOfCheeses() const {
    return m_numOfCheeses;
}

std::string CheeseShop::getShopName() const {
    return m_shopName;
}

const Cheese* CheeseShop::operator[](int index) const {
    return m_cheeses[index];
}

std::ostream& operator<<(std::ostream& os, const CheeseShop& cheeseShop) {
    os << "--------------------------" << std::endl;
    os << cheeseShop.getShopName() << std::endl;
    os << "--------------------------" << std::endl;
    if (cheeseShop.getNumOfCheeses() == 0) {
        os << "This shop is out of cheese!" << std::endl;
    } else {
        for (int i = 0; i < cheeseShop.getNumOfCheeses(); i++) {
            os << *cheeseShop.m_cheeses[i];
        }
    }
    os << "--------------------------" << std::endl;
    return os;
}
}  // namespace sdds