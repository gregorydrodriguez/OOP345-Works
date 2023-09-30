/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace sdds {
template <typename T>
class OrderedCollection : public Collection<T, 72> {
   public:
    void operator+=(T item) {
        if (this->size() < 72) {
            this->m_items[this->size()] = item;
            for (unsigned int i = this->size(); i > 0; i--) {
                if (this->m_items[i - 1] > this->m_items[i]) {
                    T temp = this->m_items[i - 1];
                    this->m_items[i - 1] = this->m_items[i];
                    this->m_items[i] = temp;
                } else {
                    break;
                }
            }
            this->incrSize();
            this->setSmallestItem(item);
            this->setLargestItem(item);
        }
    }
};
}  // namespace sdds
#endif  // SDDS_ORDEREDCOLLECTION_H