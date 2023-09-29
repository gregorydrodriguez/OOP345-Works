/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iomanip>

#include "Book.h"

namespace sdds {
template <typename T, unsigned int C>
class Collection {
    T m_items[C];
    unsigned int m_size{};
    static T m_smallestItem;
    static T m_largestItem;

   protected:
    void setSmallestItem(const T& item) {
        if (m_smallestItem > item) {
            m_smallestItem = item;
        }
    }

    void setLargestItem(const T& item) {
        if (m_largestItem < item) {
            m_largestItem = item;
        }
    }

   public:
    T getSmallestItem() const {
        return m_smallestItem;
    }

    T getLargestItem() const {
        return m_largestItem;
    }

    unsigned int size() const {
        return m_size;
    }

    unsigned int capacity() const {
        return C;
    }

    bool operator+=(const T& item) {
        if (m_size < C) {
            setSmallestItem(item);
            setLargestItem(item);
            m_items[m_size] = item;
            m_size++;
            return true;
        }
        return false;
    }

    std::ostream& print(std::ostream& os) const {
        os << "[";
        for (unsigned int i = 0; i < m_size; i++) {
            os << std::fixed << std::setprecision(1) << m_items[i];
            if (i != m_size - 1) {
                os << ",";
            }
        }
        os << "]" << std::endl;
        return os;
    }
};

template <typename T, unsigned int C>
T Collection<T, C>::m_smallestItem = 9999;
template <typename T, unsigned int C>
T Collection<T, C>::m_largestItem = -9999;
template <>
Book Collection<Book, 10>::m_smallestItem{"", 1, 10000};
template <>
Book Collection<Book, 10>::m_largestItem{"", 10000, 1};
}  // namespace sdds
#endif  // SDDS_COLLECTION_H