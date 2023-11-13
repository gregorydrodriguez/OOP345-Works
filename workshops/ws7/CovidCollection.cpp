/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "CovidCollection.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

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
        detail.m_cases = std::stoul(trim(line.substr(80, 25)));
        detail.m_deaths = std::stoul(trim(line.substr(85, 25)));
        m_covidCollection.push_back(detail);
    }
    file.close();
}
// P2
void CovidCollection::display(std::ostream& out, const std::string& country) const {
    size_t totalCases = 0;
    size_t totalDeaths = 0;
    size_t countryCases = 0;
    size_t countryDeaths = 0;
    if (country != "ALL") {
        out << "Displaying information of country = " + country << std::endl;
    }
    std::for_each(m_covidCollection.begin(), m_covidCollection.end(), [&countryCases, &countryDeaths, &totalCases, &totalDeaths, &out, country](const Covid& covid) {
        totalCases += covid.m_cases;
        totalDeaths += covid.m_deaths;
        if (covid.m_country == country) {
            countryCases += covid.m_cases;
            countryDeaths += covid.m_deaths;
        }
        if (country == "ALL" || covid.m_country == country) {
            out << covid << std::endl;
        }
    });
    if (country == "ALL") {
        out << "| " << std::right << std::setw(84) << "Total cases around the world: " + std::to_string(totalCases) << " |" << std::endl;
        out << "| " << std::right << std::setw(84) << "Total deaths around the world: " + std::to_string(totalDeaths) << " |" << std::endl;
    } else {
        double countryPercCases = (static_cast<double>(countryCases) / static_cast<double>(totalCases)) * 100.0;
        double countryPercDeaths = (static_cast<double>(countryDeaths) / static_cast<double>(totalDeaths)) * 100.0;
        out << "| " << std::right << std::setw(84) << "Total cases in " + country + ": " + std::to_string(countryCases) << " |" << std::endl;
        out << "| " << std::right << std::setw(84) << "Total deaths in " + country + ": " + std::to_string(countryDeaths) << " |" << std::endl;
        out << "| " << std::right << std::setw(86) << country + " has " + std::to_string(countryPercCases) + "% of global cases and " + std::to_string(countryPercDeaths) + "% of global deaths |" << std::endl;
    }
}

void CovidCollection::sort(const std::string& field) {
    auto compare = [field](const Covid& a, const Covid& b) {
        if (field == "city") {
            return std::tie(a.m_city, a.m_deaths) < std::tie(b.m_city, b.m_deaths);
        } else if (field == "variant") {
            return std::tie(a.m_variant, a.m_deaths) < std::tie(b.m_variant, b.m_deaths);
        } else if (field == "year") {
            return std::tie(a.m_year, a.m_deaths) < std::tie(b.m_year, b.m_deaths);
        } else if (field == "case") {
            return std::tie(a.m_cases, a.m_deaths) < std::tie(b.m_cases, b.m_deaths);
        } else {
            return std::tie(a.m_country, a.m_deaths) < std::tie(b.m_country, b.m_deaths);
        }
    };
    std::sort(m_covidCollection.begin(), m_covidCollection.end(), compare);
}

bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const {
    return std::any_of(m_covidCollection.begin(), m_covidCollection.end(), [variant, country, deaths](const Covid& covid) {
        return covid.m_variant == variant && covid.m_country == country && covid.m_deaths > deaths;
    });
}

std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const {
    std::list<Covid> deathNote;
    std::copy_if(m_covidCollection.begin(), m_covidCollection.end(), std::back_inserter(deathNote), [deaths](const Covid& covid) {
        return covid.m_deaths >= deaths;
    });
    return deathNote;
}

void CovidCollection::updateStatus() {
    std::transform(m_covidCollection.begin(), m_covidCollection.end(), m_covidCollection.begin(), [](Covid& covid) {
        if (covid.m_deaths > 300) {
            covid.m_severity = "EPIDEMIC";
        } else if (covid.m_deaths < 50) {
            covid.m_severity = "EARLY";
        } else {
            covid.m_severity = "MILD";
        }
        return covid;
    });
}

std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
    out << "| " << std::left << std::setw(21) << theCovid.m_country;
    out << " | " << std::setw(15) << theCovid.m_city;
    out << " | " << std::setw(20) << theCovid.m_variant;
    out << std::right;
    if (theCovid.m_year >= 0) {
        out << " | " << std::setw(6) << theCovid.m_year;
    } else {
        out << " | " << std::setw(6) << "";
    }
    out << " | " << std::setw(4) << theCovid.m_cases;
    out << " | " << std::setw(3) << theCovid.m_deaths << " | ";
    out << "| " << std::setw(8) << theCovid.m_severity << " |";
    return out;
}

std::string CovidCollection::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
}  // namespace sdds