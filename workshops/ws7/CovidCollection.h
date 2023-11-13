/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <iostream>
#include <list>
#include <vector>

namespace sdds {
struct Covid {
    std::string m_country{};
    std::string m_city{};
    std::string m_variant{};
    int m_year{};
    size_t m_cases;
    size_t m_deaths;
    // P2
    std::string m_severity{"General"};
};

class CovidCollection {
    std::vector<Covid> m_covidCollection{};

   public:
    CovidCollection(){};
    CovidCollection(const std::string& textfile);
    // void display(std::ostream& out) const;
    std::string trim(const std::string& str);
    // P2
    void display(std::ostream& out = std::cout, const std::string& country = "ALL") const;
    void sort(const std::string& field = "country");
    bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
    std::list<Covid> getListForDeaths(unsigned int deaths) const;
    void updateStatus();
};

std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}  // namespace sdds
#endif  // SDDS_COVIDCOLLECTION_H