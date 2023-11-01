/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Directory.h"

#include <vector>

namespace sdds {
Directory::~Directory() {
    for (auto& resource : m_contents) {
        delete resource;
    }
    m_contents.clear();
}

Directory::Directory(const std::string& name) {
    m_name = name;
}

void Directory::update_parent_path(const std::string& path) {
    m_parent_path = path;
    for (auto& resource : m_contents) {
        resource->update_parent_path(m_parent_path);
    }
}

NodeType Directory::type() const {
    return NodeType::DIR;
}

std::string Directory::path() const {
    return m_parent_path + m_name;
}

std::string Directory::name() const {
    return m_name;
}

int Directory::count() const {
    return m_contents.size();
}

size_t Directory::size() const {
    size_t totalSize = 0;
    for (auto& resource : m_contents) {
        totalSize += resource->size();
    }
    return totalSize;
}

Directory& Directory::operator+=(Resource* resource) {
    for (auto& existingResource : m_contents) {
        if (existingResource->name() == resource->name()) {
            throw std::runtime_error("Resource with the same name already exists");
        }
    }
    m_contents.push_back(resource);
    resource->update_parent_path(this->path());
    return *this;
}

Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags) {
    if (std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end()) {
        for (auto& resource : m_contents) {
            if (resource->type() == NodeType::DIR) {
                auto foundResource = dynamic_cast<Directory*>(resource)->find(name, flags);
                if (foundResource != nullptr) {
                    return foundResource;
                }
            }
        }
    }
    for (auto& resource : m_contents) {
        if (resource->name() == name) {
            return resource;
        }
    }
    return nullptr;
}
}  // namespace sdds