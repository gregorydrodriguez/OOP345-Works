/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>

#include "Workstation.h"

namespace sdds {
class LineManager {
    std::vector<Workstation*> m_activeLine{};
    size_t m_cntCustomerOrder{};
    Workstation* m_firstStation{};

    Workstation* findFirstStation(const std::vector<Workstation*>& stations);
    Workstation* searchStations(const std::vector<Workstation*>& stations, const std::vector<Workstation*>::const_iterator currStation);

   public:
    LineManager(const std::string& file, const std::vector<Workstation*>& stations);
    void reorderStations();
    bool run(std::ostream& os);
    void display(std::ostream& os) const;
};
}  // namespace sdds
#endif  // SDDS_LINEMANAGER_H