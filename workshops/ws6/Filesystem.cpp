/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Filesystem.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "File.h"

namespace sdds {
Filesystem::~Filesystem() {
    delete m_root;
}

Filesystem::Filesystem(Filesystem&& src) {
    m_root = std::move(src.m_root);
    m_current = std::move(src.m_current);
}

Filesystem& Filesystem::operator=(Filesystem&& src) {
    if (this != &src) {
        delete m_root;
        m_root = std::move(src.m_root);
        m_current = std::move(src.m_current);
    }
    return *this;
}

Filesystem::Filesystem(const std::string filename, const std::string root) {
    m_root = new Directory(root);
    m_current = m_root;
    std::ifstream file(filename);
    if (file.fail()) {
        throw std::invalid_argument("File failed to open.");
    }
    std::string line;
    while (std::getline(file, line)) {
        Directory* currentDir = m_root;
        if (line.find('|') != std::string::npos) {
            // File
            std::vector<std::string> lineTokens = split(line, '|');                // [0]: "images/cat.jpg" [1]: "This is an image of a cute cat!"
            std::vector<std::string> pathTokens = split(lineTokens.front(), '/');  // [0]: "images" [1]: "cat.jpg" (the last element is always the filename)
            for (size_t i = 0; i < pathTokens.size() - 1; i++) {
                Resource* foundResource = currentDir->find(pathTokens[i] + '/');
                if (foundResource == nullptr) {
                    Directory* newDir = new Directory(pathTokens[i] + '/');
                    *currentDir += newDir;
                    currentDir = newDir;
                } else {
                    currentDir = static_cast<Directory*>(foundResource);
                }
            }
            if (currentDir->find(pathTokens.back()) == nullptr) {
                File* newFile = new File(pathTokens.back(), lineTokens.back());
                *currentDir += newFile;
            }
        } else {
            // Directory
            std::vector<std::string> pathTokens = split(line, '/');
            for (size_t i = 0; i < pathTokens.size(); i++) {
                Resource* foundResource = currentDir->find(pathTokens[i] + '/');
                if (foundResource == nullptr) {
                    Directory* newDir = new Directory(pathTokens[i] + '/');
                    *currentDir += newDir;
                    currentDir = newDir;
                } else {
                    currentDir = static_cast<Directory*>(foundResource);
                }
            }
        }
    }
}

std::vector<std::string> Filesystem::split(std::string str, const char delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        tokens.push_back(this->trimWhitespace(str.substr(0, pos)));
        str.erase(0, pos + 1);
    }
    str = this->trimWhitespace(str);
    if (!str.empty()) {
        tokens.push_back(str);
    }
    return tokens;
}

std::string Filesystem::trimWhitespace(std::string str) {
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}

Filesystem& Filesystem::operator+=(Resource* resource) {
    *m_current += resource;
    return *this;
}

Directory* Filesystem::change_directory(const std::string& directory) {
    if (directory.empty()) {
        m_current = m_root;
    } else {
        Resource* foundResourceResource = m_current->find(directory);
        if (foundResourceResource == nullptr || foundResourceResource->type() == NodeType::FILE) {
            throw std::invalid_argument("Cannot change directory! " + directory + " not foundResource!");
        }
        m_current = static_cast<Directory*>(foundResourceResource);
    }
    return m_current;
}

Directory* Filesystem::get_current_directory() const {
    return m_current;
}
}  // namespace sdds