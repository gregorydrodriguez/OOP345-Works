/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H

#include <string>
#include <vector>

#include "Resource.h"

namespace sdds {
class Directory : public Resource {
    std::vector<Resource*> m_contents{};

    Directory(const Directory&) = delete;
    Directory& operator=(const Directory&) = delete;
    Directory(Directory&&) = delete;
    Directory& operator=(Directory&&) = delete;

   public:
    ~Directory();
    Directory(){};
    Directory(const std::string& name);
    void update_parent_path(const std::string& path);
    NodeType type() const;
    std::string path() const;
    std::string name() const;
    int count() const;
    size_t size() const;
    Directory& operator+=(Resource* resource);
    Resource* find(const std::string& name, const std::vector<OpFlags>& flags = {});
    // P2
    void remove(const std::string& resource, const std::vector<OpFlags>& flags = {});
    void display(std::ostream& os = std::cout, const std::vector<FormatFlags>& flags = {}) const;
};
}  // namespace sdds
#endif  // SDDS_DIRECTORY_H