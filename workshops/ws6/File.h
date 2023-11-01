/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include <string>

#include "Resource.h"

namespace sdds {
class File : public Resource {
    std::string m_contents{};

   public:
    File(){};
    File(const std::string& name, const std::string& contents = "");
    void update_parent_path(const std::string&);
    NodeType type() const;
    std::string path() const;
    std::string name() const;
    int count() const;
    size_t size() const;
};
}  // namespace sdds
#endif  // SDDS_FILE_H