/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "File.h"

namespace sdds {
File::File(const std::string& name, const std::string& contents) : m_contents(contents) {
    m_name = name;
}

void File::update_parent_path(const std::string& path) {
    m_parent_path = path;
}

NodeType File::type() const {
    return NodeType::FILE;
}

std::string File::path() const {
    return m_parent_path + m_name;
}

std::string File::name() const {
    return m_name;
}

int File::count() const {
    return -1;
}
size_t File::size() const {
    return m_contents.length();
}
}  // namespace sdds