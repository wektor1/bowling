#pragma once
#include <string>

class InputValidation
{
private:
    std::string data;
    std::string substring;
    bool isPlayerNameCorrect;
    bool checkNumberofFrames();
    bool checkAllChars();
    bool checknNighboringNumbers(const char& ch1, const char& ch2);
    bool checkStrike(const int& position);
    bool checkSpareOrMiss(const int& position);
    bool checkFrameSeparator(const int& position);
    bool checkNumberOfPinchedPins(const int& position);
    bool checkFirstAndLastSeparator();
public:
    explicit InputValidation(const std::string& data_);
    std::string getSubstring() const;
    bool checkInputData();
    virtual ~InputValidation();
};

