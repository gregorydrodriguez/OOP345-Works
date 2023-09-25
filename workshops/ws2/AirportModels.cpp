/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "AirportModels.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <limits>

namespace sdds {

// Airport Class
Airport::Airport(Airport& src) {
    m_code = src.m_code;
    m_name = src.m_name;
    m_city = src.m_city;
    m_state = src.m_state;
    m_country = src.m_country;
    m_latitude = src.m_latitude;
    m_longitude = src.m_longitude;
}

Airport::Airport(const char* code, const char* name, const char* city,
                 const char* state, const char* country, const double latitude,
                 const double longitude) {
    m_code = code;
    m_name = name;
    m_city = city;
    m_state = state;
    m_country = country;
    m_latitude = latitude;
    m_longitude = longitude;
}

Airport& Airport::operator=(const Airport& src) {
    if (this != &src) {
        m_code = src.m_code;
        m_name = src.m_name;
        m_city = src.m_city;
        m_state = src.m_state;
        m_country = src.m_country;
        m_latitude = src.m_latitude;
        m_longitude = src.m_longitude;
    }
    return *this;
}

// AirportLog Class
AirportLog::AirportLog(char* filename) {
    std::ifstream log;
    log.open(filename);
    if (log.is_open()) {
        std::string line;
        bool skipHeader = true;
        while (std::getline(log, line, '\n')) {
            if (skipHeader) {
                skipHeader = false;
                continue;
            }
            m_count++;
        }
        m_airports = new Airport[m_count]{};
        log.clear();
        log.seekg(0, std::ios::beg);
        std::getline(log, line, '\n');
        size_t i = 0;
        while (log) {
            std::getline(log, m_airports[i].m_code, ',');
            std::getline(log, m_airports[i].m_name, ',');
            std::getline(log, m_airports[i].m_city, ',');
            std::getline(log, m_airports[i].m_state, ',');
            std::getline(log, m_airports[i].m_country, ',');
            log >> m_airports[i].m_latitude;
            log.ignore(std::numeric_limits<std::streamsize>::max(), ',');
            log >> m_airports[i].m_longitude;
            log.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i++;
        }
    }
}

AirportLog::AirportLog(const AirportLog& src) {
    m_count = src.m_count;
    m_airports = new Airport[m_count];
    for (size_t i = 0; i < m_count; i++) {
        m_airports[i] = src.m_airports[i];
    }
}

AirportLog* AirportLog::operator=(const AirportLog& src) {
    if (this != &src) {
        m_count = src.m_count;
        m_airports = new Airport[m_count];
        for (size_t i = 0; i < m_count; i++) {
            m_airports[i] = src.m_airports[i];
        }
    }
    return this;
}

AirportLog::~AirportLog() {
    delete[] m_airports;
}

AirportLog::AirportLog(AirportLog&& src) {
    m_count = src.m_count;
    m_airports = src.m_airports;
    src.m_count = 0;
    src.m_airports = nullptr;
}
/*
AirportLog& operator=(AirportLog&& src) {
        if(this != &src) {
            delete[] m_airports;
            m_count = src.m_count;
            m_airports = src.m_airports;
            src.m_count = 0;
            src.m_airports = nullptr;
        }
}
*/
void AirportLog::addAirport(const Airport& src) {
    Airport* airportArray = new Airport[m_count + 1];
    for (size_t i = 0; i < m_count; i++) {
        airportArray[i] = m_airports[i];
    }
    airportArray[m_count] = src;
    m_count++;
    delete[] m_airports;
    m_airports = airportArray;
}

AirportLog AirportLog::findAirport(const char* state, const char* country) {
    AirportLog log;
    for (size_t i = 0; i < m_count; i++) {
        if (m_airports[i].m_state.compare(state) == 0 &&
            m_airports[i].m_country.compare(country) == 0) {
            log.addAirport(m_airports[i]);
        }
    }
    return log;
}

Airport AirportLog::operator[](size_t index) const {
    if (m_count > index) {
        return m_airports[index];
    } else {
        Airport airport;
        return airport;
    }
}

AirportLog::operator size_t() const {
    return m_count;
}

std::ostream& operator<<(std::ostream& os, const Airport& src) {
    if (!src.m_code.empty() && !src.m_name.empty() && !src.m_city.empty() &&
        !src.m_state.empty() && !src.m_country.empty() &&
        src.m_latitude != 0 && src.m_longitude != 0) {
        os << std::setfill('.') << std::setw(20) << std::right << "Airport Code"
           << " : ";
        os << std::setfill('.') << std::setw(30) << std::left << src.m_code << std::endl;
        os << std::setfill('.') << std::setw(20) << std::right << "Airport Name"
           << " : ";
        os << std::setfill('.') << std::setw(30) << std::left << src.m_name << std::endl;
        os << std::setfill('.') << std::setw(20) << std::right << "Airport City"
           << " : ";
        os << std::setfill('.') << std::setw(30) << std::left << src.m_city << std::endl;
        os << std::setfill('.') << std::setw(20) << std::right << "Airport State"
           << " : ";
        os << std::setfill('.') << std::setw(30) << std::left << src.m_state << std::endl;
        os << std::setfill('.') << std::setw(20) << std::right << "Airport Country"
           << " : ";
        os << std::setfill('.') << std::setw(30) << std::left << src.m_country << std::endl;
        os << std::setfill('.') << std::setw(20) << std::right << "Airport Latitude"
           << " : ";
        os << std::setfill('.') << std::setw(30) << std::left << src.m_latitude << std::endl;
        os << std::setfill('.') << std::setw(20) << std::right << "Airport Longitude"
           << " : ";
        os << std::setfill('.') << std::setw(30) << std::left << src.m_longitude << std::endl;
    } else {
        os << "Empty Airport";
    }
    return os;
}
}  // namespace sdds