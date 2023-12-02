/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "LineManager.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "Utilities.h"
#include "Workstation.h"

namespace sdds {
LineManager::LineManager(const std::string& filename, const std::vector<Workstation*>& stations) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::ios_base::failure("Cannot open " + filename);
    }
    Utilities util;
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = 0;
        bool more = true;
        std::string currentToken{};
        std::string nextToken{};
        std::__1::vector<sdds::Workstation*>::const_iterator currentWorkstation{};
        std::__1::vector<sdds::Workstation*>::const_iterator nextWorkstation{};
        currentToken = util.extractToken(line, pos, more);
        currentWorkstation = std::find_if(stations.begin(), stations.end(), [currentToken](const Workstation* station) {
            return station->getItemName() == currentToken;
        });
        if (more) {
            nextToken = util.extractToken(line, pos, more);
            nextWorkstation = std::find_if(stations.begin(), stations.end(), [nextToken](const Workstation* station) {
                return station->getItemName() == nextToken;
            });
            (*currentWorkstation)->setNextStation(*nextWorkstation);
        }
        m_activeLine.push_back(*currentWorkstation);
    }
    if (m_firstStation == nullptr) {
        m_firstStation = findFirstStation(m_activeLine);
    }
    m_cntCustomerOrder = g_pending.size();
}

void LineManager::reorderStations() {
    m_activeLine.clear();
    Workstation* currStation = m_firstStation;
    while (currStation != nullptr) {
        m_activeLine.push_back(currStation);
        currStation = currStation->getNextStation();
    }
}

bool LineManager::run(std::ostream& os) {
    static size_t iteration;
    os << "Line Manager Iteration : " << ++iteration << std::endl;
    size_t oldCompletedSize = g_completed.size();
    if (!g_pending.empty()) {
        *m_firstStation += std::move(g_pending.front());
        g_pending.pop_front();
    }
    for (Workstation* station : m_activeLine) {
        station->fill(os);
    }
    for (Workstation* station : m_activeLine) {
        station->attemptToMoveOrder();
    }
    size_t completedIteration = g_completed.size() - oldCompletedSize;
    if (completedIteration > 1) {
        for (size_t i = 0; i < completedIteration / 2; i++) {
            size_t indexA = oldCompletedSize + i;
            size_t indexB = g_completed.size() - 1 - i;
            std::swap(g_completed[indexA], g_completed[indexB]);
        }
    }
    return g_pending.empty() && g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
}

void LineManager::display(std::ostream& os) const {
    for (Workstation* station : m_activeLine) {
        station->display(os);
    }
}

// Helpers
Workstation* LineManager::findFirstStation(const std::vector<Workstation*>& stations) {
    auto lastStation = std::find_if(stations.begin(), stations.end(), [](const Workstation* station) {
        return station->getNextStation() == nullptr;
    });
    return searchStations(stations, lastStation);
}

Workstation* LineManager::searchStations(const std::vector<Workstation*>& stations, std::__1::vector<sdds::Workstation*>::const_iterator currStation) {
    auto prevStation = std::find_if(stations.begin(), stations.end(), [currStation](const Workstation* station) {
        return station->getNextStation() == *currStation;
    });
    if (prevStation == stations.end()) {
        return *currStation;
    } else {
        return searchStations(stations, prevStation);
    }
}
}  // namespace sdds