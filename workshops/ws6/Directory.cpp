/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Directory.h"

#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

namespace sdds {
Directory::~Directory() {
    for (Resource* resource : m_contents) {
        delete resource;
    }
    m_contents.clear();
}

Directory::Directory(const std::string& name) {
    m_name = name;
}

void Directory::update_parent_path(const std::string& path) {
    m_parent_path = path;
    for (Resource* resource : m_contents) {
        resource->update_parent_path(this->path());
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
    for (Resource* resource : m_contents) {
        totalSize += resource->size();
    }
    return totalSize;
}

Directory& Directory::operator+=(Resource* resource) {
    for (Resource* existingResource : m_contents) {
        if (existingResource->name() == resource->name()) {
            throw std::runtime_error("Resource with the same name already exists");
        }
    }
    m_contents.push_back(resource);
    resource->update_parent_path(this->path());
    return *this;
}

Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags) {
    // bool isRecursive = false;
    // for (auto flag : flags) {
    //     if (flag == OpFlags::RECURSIVE) {
    //         isRecursive = true;
    //     }
    // }
    auto isRecursive = std::find_if(flags.begin(), flags.end(), [](OpFlags flag) { return flag == OpFlags::RECURSIVE; });
    if (isRecursive != flags.end()) {  // Just "if (isRecursive)" if using first implementation
        for (Resource* resource : m_contents) {
            if (resource->type() == NodeType::DIR) {
                Resource* foundResource = static_cast<Directory*>(resource)->find(name, flags);
                if (foundResource != nullptr) {
                    return foundResource;
                }
            }
        }
    }
    for (Resource* resource : m_contents) {
        if (resource->name() == name) {
            return resource;
        }
    }
    return nullptr;
}
// P2
void Directory::remove(const std::string& resource, const std::vector<OpFlags>& flags) {
    Resource* foundResource = find(resource, flags);
    if (foundResource != nullptr) {
        if (foundResource->type() == NodeType::DIR) {
            auto isRecursive = std::find_if(flags.begin(), flags.end(), [](OpFlags flag) { return flag == OpFlags::RECURSIVE; });
            if (isRecursive == flags.end()) {
                throw std::invalid_argument(resource + " is a directory. Pass the recursive flag to delete directories.");
            }
        }
        std::vector<Resource*>::iterator iter = std::find(m_contents.begin(), m_contents.end(), foundResource);
        m_contents.erase(iter);
        delete foundResource;
    } else {
        throw std::invalid_argument(resource + " does not exist in " + this->name());
    }
}

void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flags) const {
    os << "Total size: " << this->size() << " bytes" << std::endl;
    for (Resource* resource : m_contents) {
        if (resource->type() == NodeType::DIR) {
            os << "D";
        } else {
            os << "F";
        }
        os << " | " << std::left << std::setw(15) << resource->name() << " |";
        auto isRecursive = std::find_if(flags.begin(), flags.end(), [](FormatFlags flag) {
            return flag == FormatFlags::LONG;
        });
        if (isRecursive != flags.end()) {
            if (resource->type() == NodeType::DIR) {
                os << std::right << " " << std::setw(2) << resource->count() << " | ";
                os << std::right << std::setw(10) << std::to_string(resource->size()) + " bytes"
                   << " |";
            } else {
                os << std::right <<  " " << std::setw(2) << "  "
                   << " | ";
                os << std::right << std::setw(10) << std::to_string(resource->size()) + " bytes"
                   << " |";
            }
        }
        os << std::endl;
    }
}
}  // namespace sdds
