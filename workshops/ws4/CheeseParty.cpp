/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "CheeseParty.h"

namespace sdds {
CheeseParty::~CheeseParty() {
    // for (int i = 0; i < m_numOfCheeses; i++) {
    //     delete m_pCheeses[i];
    // }
    delete[] m_pCheeses;
}

CheeseParty::CheeseParty(const CheeseParty& cheeseParty) {
    m_numOfCheeses = cheeseParty.m_numOfCheeses;
    m_pCheeses = new const Cheese*[m_numOfCheeses];
    for (int i = 0; i < m_numOfCheeses; i++) {
        m_pCheeses[i] = cheeseParty.m_pCheeses[i];
    }
}

CheeseParty& CheeseParty::operator=(const CheeseParty& cheeseParty) {
    if (this != &cheeseParty) {
        delete[] m_pCheeses;
        if (cheeseParty.m_pCheeses != nullptr) {
            m_numOfCheeses = cheeseParty.m_numOfCheeses;
            m_pCheeses = new const Cheese*[m_numOfCheeses];
            for (int i = 0; i < m_numOfCheeses; i++) {
                m_pCheeses[i] = cheeseParty.m_pCheeses[i];
            }
        } else {
            m_pCheeses = nullptr;
        }
    }
    return *this;
}

CheeseParty::CheeseParty(CheeseParty&& cheeseParty) {
    *this = cheeseParty;
    cheeseParty.setDefault();
}

CheeseParty& CheeseParty::operator=(CheeseParty&& cheeseParty) {
    if (this != &cheeseParty) {
        *this = cheeseParty;
        cheeseParty.setDefault();
    }
    return *this;
}

void CheeseParty::setDefault() {
    m_pCheeses = nullptr;
    m_numOfCheeses = 0;
}

int CheeseParty::getNumOfCheeses() const {
    return m_numOfCheeses;
}

CheeseParty& CheeseParty::addCheese(const Cheese& cheese) {
    for (int i = 0; i < m_numOfCheeses; i++) {
        if (m_pCheeses[i] == &cheese) {
            return *this;
        }
    }
    const Cheese** newCheeses = new const Cheese*[m_numOfCheeses + 1];
    for (int i = 0; i < m_numOfCheeses; i++) {
        newCheeses[i] = m_pCheeses[i];
    }
    delete[] m_pCheeses;
    m_pCheeses = newCheeses;
    m_pCheeses[m_numOfCheeses] = &cheese;
    m_numOfCheeses++;
    return *this;
}

CheeseParty& CheeseParty::removeCheese() {
    int removedCheeses = 0;
    for (int i = 0; i < m_numOfCheeses; i++) {
        if (m_pCheeses[i]->getWeight() == 0) {
            m_pCheeses[i] = nullptr;
            removedCheeses++;
        }
    }
    const Cheese** newCheeses = new const Cheese*[m_numOfCheeses - removedCheeses];
    for (int i = 0; i < m_numOfCheeses; i++) {
        int j = 0;
        if (m_pCheeses[i] != nullptr) {
            newCheeses[j] = m_pCheeses[i];
            j++;
        }
    }
    delete[] m_pCheeses;
    m_pCheeses = newCheeses;
    m_numOfCheeses -= removedCheeses;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const CheeseParty& cheeseParty) {
    os << "--------------------------" << std::endl;
    os << "Cheese Party" << std::endl;
    os << "--------------------------" << std::endl;
    if (cheeseParty.getNumOfCheeses() == 0) {
        os << "This party is just getting started!" << std::endl;
    } else {
        for (int i = 0; i < cheeseParty.getNumOfCheeses(); i++) {
            os << *cheeseParty.m_pCheeses[i];
        }
    }
    os << "--------------------------" << std::endl;
    return os;
}
}  // namespace sdds