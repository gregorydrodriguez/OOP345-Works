/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H

#include "Directory.h"

namespace sdds {
class Filesystem {
    Directory* m_root{};
    Directory* m_current{};

    Filesystem(const Filesystem&) = delete;
    Filesystem& operator=(const Filesystem&) = delete;
    std::vector<std::string> split(const std::string str, const char delimiter);
    std::string trimWhitespace(std::string str);

   public:
    ~Filesystem();
    Filesystem(Filesystem&&);
    Filesystem& operator=(Filesystem&&);
    Filesystem(const std::string filename, const std::string root = "");
    Filesystem& operator+=(Resource* resource);
    Directory* change_directory(const std::string& directory = "");
    Directory* get_current_directory() const;
};
}  // namespace sdds
#endif  // SDDS_FILESYSTEM_H