/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H
#include <iostream>
#include <string>

namespace sdds {
class Airport {
    std::string m_code{};
    std::string m_name{};
    std::string m_city{};
    std::string m_state{};
    std::string m_country{};
    double m_latitude{};
    double m_longitude{};
    friend std::ostream& operator<<(std::ostream& os, const Airport& src);
    friend class AirportLog;

   public:
    Airport(){};
    Airport(const char* code, const char* name, const char* city,
            const char* state, const char* country, const double latitude,
            const double longitude);
    Airport(Airport& src);
    Airport& operator=(const Airport& src);
};

class AirportLog {
    Airport* m_airports{};
    size_t m_count{};

   public:
    AirportLog(){};
    AirportLog(char* filename);
    AirportLog(AirportLog& src);
    AirportLog* operator=(AirportLog& src);
    ~AirportLog();
    void addAirport(const Airport& src);
    AirportLog findAirport(const char* state, const char* country);
    Airport operator[](size_t index) const;
    operator size_t() const;
};
}  // namespace sdds
#endif  // SDDS_AIRPORTMODELS_H