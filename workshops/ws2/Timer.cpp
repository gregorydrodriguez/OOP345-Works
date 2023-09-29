/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/

#include "Timer.h"

namespace sdds {
void Timer::start() {
    start_time = std::chrono::system_clock::now();
}

void Timer::stop() {
    end_time = std::chrono::system_clock::now();
}
}  // namespace sdds