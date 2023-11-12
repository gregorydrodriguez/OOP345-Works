/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "CovidCollection.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

namespace sdds {
    CovidCollection::CovidCollection(const std::string& textfile) {
        std::ifstream file(textfile);
        if (!file.is_open()) {
            throw std::runtime_error(textfile + " does not exist");
        }
        std::string line;
        while (getline(file, line)) {
            Covid detail;
            detail.m_country = trim(line.substr(0, 25));
            detail.m_city = trim(line.substr(25, 25));
            detail.m_variant = trim(line.substr(50, 25));
            detail.m_year = std::stoi(trim(line.substr(75, 5)));
            detail.m_cases = std::stoul(trim(line.substr(80,25)));
            detail.m_deaths = std::stoul(trim(line.substr(85,25)));
            m_covidCollection.push_back(detail);
        }
        file.close();
    }

    void CovidCollection::display(std::ostream& out = std::cout) const {
        for (const Covid& covid : m_covidCollection) {
            out << covid << std::endl;
        }
    }

    std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
        out << "| " << std::setw(21) << theCovid.m_country;
        out << " | " << std::setw(15) << theCovid.m_city;
        out << " | " << std::setw(20) << theCovid.m_variant;
        if (theCovid.m_year >= 0) {
            out << " | " << std::setw(6) << theCovid.m_year;
        } else {
            out << " | " << std::setw(6) << "";
        }
        out << " | " << std::setw(4) << theCovid.m_cases;
        out << " | " << std::setw(3) << theCovid.m_deaths << " |";
        return out;
    }

    std::string CovidCollection::trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }
} // sdds