#pragma once
#include <stdexcept>
#include <string>

class InvalidFile : public std::invalid_argument
{
public:
    InvalidFile(const std::string path)
        : invalid_argument("Can not open the file: " + path)
    {}
};