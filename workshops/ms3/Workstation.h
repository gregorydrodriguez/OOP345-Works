/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>

#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {
extern std::deque<CustomerOrder> g_pending;
extern std::deque<CustomerOrder> g_completed;
extern std::deque<CustomerOrder> g_incomplete;

class Workstation : public Station {
    std::deque<CustomerOrder> m_orders{};
    Workstation* m_pNextStation{};

    Workstation(const Workstation&) = delete;
    Workstation& operator=(const Workstation&) = delete;
    Workstation(Workstation&&) = delete;
    Workstation& operator=(Workstation&&) = delete;

   public:
    Workstation(const std::string& stationInput) : Station(stationInput){};
    void fill(std::ostream& os);
    bool attemptToMoveOrder();
    void setNextStation(Workstation* station);
    Workstation* getNextStation() const;
    void display(std::ostream& os) const;
    Workstation& operator+=(CustomerOrder&& newOrder);
};
}  // namespace sdds
#endif  // SDDS_WORKSTATION_H