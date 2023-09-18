/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "RideRequest.h"

#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>

double g_taxrate;
double g_discount;

namespace sdds {
RideRequest::RideRequest(const RideRequest& src) {
    strcpy(m_custName, src.m_custName);
    m_custDetails = new char[strlen(src.m_custDetails) + 1];
    strcpy(m_custDetails, src.m_custDetails);
    m_price = src.m_price;
    m_discount = src.m_discount;
}

RideRequest& RideRequest::operator=(RideRequest& src) {
    if (this != &src) {
        strcpy(m_custName, src.m_custName);
        delete[] m_custDetails;
        m_custDetails = new char[strlen(src.m_custDetails) + 1];
        strcpy(m_custDetails, src.m_custDetails);
        m_price = src.m_price;
        m_discount = src.m_discount;
    }
    return *this;
}

RideRequest::~RideRequest() {
    delete[] m_custDetails;
}

std::istream& RideRequest::read(std::istream& is) {
    if (is) {
        is.getline(m_custName, std::numeric_limits<std::streamsize>::max(), ',');
        std::string s;
        std::getline(is, s, ',');
        // NOTE: std::getline(is, s) is the same as std::getline(is, s, '\n')
        m_custDetails = new char[s.length() + 1];
        strcpy(m_custDetails, s.c_str());
        // char details[255];
        // is.getline(details, std::numeric_limits<std::streamsize>::max(), ',');
        // m_custDetails = new char[strlen(details) + 1];
        // strcpy(m_custDetails, details);
        is >> m_price;
        is.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        char discount{};
        is >> discount;
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (discount == 'N') {
            m_discount = false;
        } else if (discount == 'Y') {
            m_discount = true;
        }
    }
    return is;
}

void RideRequest::display() {
    double fullPrice = ((m_price * g_taxrate) + m_price);
    static int counter = 0;
    if (m_custName[0] != '\0') {
        std::cout << std::left << std::setw(2) << ++counter << ". ";
        std::cout << std::left << std::setw(10) << m_custName << "|";
        std::cout << std::left << std::setw(25) << m_custDetails << "|";
        std::cout << std::left << std::setw(12) << std::fixed << std::setprecision(2) << fullPrice << "|";
        if (m_discount) {
            double discountFullPrice = fullPrice - g_discount;
            std::cout << std::right << std::setw(13) << std::fixed << std::setprecision(2) << discountFullPrice;
        }
        std::cout << std::endl;
    } else {
        std::cout << std::left << std::setw(2) << ++counter << ". ";
        std::cout << "No Ride Request" << std::endl;
    }
}
}  // namespace sdds