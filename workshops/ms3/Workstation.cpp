#include "Workstation.h"

#include <deque>

#include "CustomerOrder.h"

namespace sdds {
std::deque<CustomerOrder> g_pending{};
std::deque<CustomerOrder> g_completed{};
std::deque<CustomerOrder> g_incomplete{};

void Workstation::fill(std::ostream& os) {
    if (!m_orders.empty()) {
        CustomerOrder& order = m_orders.front();
        order.fillItem(*this, os);
    }
}

bool Workstation::attemptToMoveOrder() {
    if (!m_orders.empty()) {
        CustomerOrder& order = m_orders.front();
        if (order.isOrderFilled()) {
            g_completed.push_back(std::move(order));
            m_orders.pop_front();
            return true;
        } else if (!order.isItemFilled(getItemName()) && getQuantity() > 0) {
            return false;
        } else if (m_pNextStation) {
            *m_pNextStation += std::move(order);
            m_orders.pop_front();
            return true;
        } else {
            g_incomplete.push_back(std::move(order));
            m_orders.pop_front();
            return true;
        }
    } else {
        return false;
    }
}

void Workstation::setNextStation(Workstation* station) {
    m_pNextStation = station;
}

Workstation* Workstation::getNextStation() const {
    return m_pNextStation;
}

void Workstation::display(std::ostream& os) const {
    os << this->getItemName() << " --> ";
    os << (m_pNextStation ? m_pNextStation->getItemName() : "End of Line") << "\n";
}

Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
    m_orders.push_back(std::move(newOrder));
    return *this;
}
}  // namespace sdds