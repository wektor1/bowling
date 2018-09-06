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

class IncorrectInputData : public std::invalid_argument
{
public:
    explicit IncorrectInputData(const std::string& inputData)
        : invalid_argument("Incorrect input data: " + inputData)
    {}
};
