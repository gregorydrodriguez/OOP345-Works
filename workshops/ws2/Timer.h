/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>
namespace sdds {
class Timer {
    std::chrono::system_clock::time_point start_time;
    std::chrono::system_clock::time_point end_time;

   public:
    void start();
    void stop();
};
}  // namespace sdds
#endif  // SDDS_TIMER_H