#pragma once
#include <stdexcept>
#include <string>

class InvalidFile : public std::invalid_argument
{
public:
    explicit InvalidFile(const std::string& path)
        : invalid_argument("Can not open the file: " + path)
    {}
};
