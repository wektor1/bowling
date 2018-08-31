#include <../inc/InputValidation.hpp>
#include <algorithm>
#include <iostream>
#include <cctype>

InputValidation::InputValidation(const std::string& data_) :
    data(data_),
    substring(data.substr(data.find(':') + 1, data.size()))
{
    (data.find_first_of(':') != 0) ? isPlayerNameCorrect = true : isPlayerNameCorrect = false;
}

std::string InputValidation::getSubstring() const
{
    return substring;
}

bool InputValidation::checkNumberofFrames()
{
    auto numberOfFrames = std::count_if(substring.begin(), substring.end(), [](char stick) {return stick == '|'; });
    if (numberOfFrames >= 1 && numberOfFrames <= 11)  return true;
    else return false;
}

bool InputValidation::checkAllChars()
{
    for (auto& sign : substring)
    {
        if ((sign != 'x' &&
            sign != '-' &&
            sign != '/' &&
            sign != '|' &&
            !isdigit(sign)) ||
            sign == '0')
            return false;
    }
    return true;
}

bool InputValidation::checknNighboringNumbers(const char& ch1, const char& ch2)
{
    int firstNumber = ch1 - '0';
    int secondNumber = ch2 - '0';
    if (firstNumber + secondNumber > 9) return false;
    else return true;
}

bool InputValidation::checkStrike(const int& position)
{
    if ((position - 1) != 0)
    {
        if (substring[position - 2] != '|') return false;
    }
    return true;
}

bool InputValidation::checkSpareOrMiss(const int& position)
{
    if (substring[position - 2] == '|' ||
        substring[position - 2] == 'x' ||
        substring[position - 2] == '/' ||
        ((position - 3 >= 0) && substring[position - 3] != '|'))
        return false;
    return true;
}

bool InputValidation::checkFrameSeparator(const int& position)
{
    if (position != substring.find_last_of('|') ||
        std::count(substring.begin(), substring.end(), '|') != 11)
        return false;
    else
    {
        switch (substring[position - 2])
        {
        case 'x':
            if (substring.size() == substring.find_last_of('|') + 2)
            {
                if (substring[position + 1] != 'x')
                {
                    return false;
                }
            }
            else if (substring.size() == substring.find_last_of('|') + 3)
            {
                if (substring[position + 1] == '/' || substring[position + 1] == 'x')
                {
                    return false;
                }

                if (isdigit(substring[position + 1]) && isdigit(substring[position + 2]))
                {
                    if (!checknNighboringNumbers(substring[position + 1], substring[position + 2]))
                    {
                        return false;
                    }
                }
            }
            else return false;
            break;

        case '/':
            if (substring.size() != substring.find_last_of('|') + 2 || substring[position + 1] == '/')
                return false;
            break;

        default:
            if (substring.size() != substring.find_last_of('|') + 1)
                return false;
            break;
        }
    }
    return true;
}

bool InputValidation::checkNumberOfPinchedPins(const int& position)
{
    if (isdigit(substring[position - 1]))
    {
        if (substring[position - 2] == '|' ||
            substring[position - 2] == 'x' ||
            substring[position - 2] == '/' ||
            ((position - 3 >= 0) && substring[position - 3] != '|'))
        {
            return false;
        }
        else if (isdigit(substring[position - 2]) && !checknNighboringNumbers(substring[position - 1], substring[position - 2]))
        {
            return false;
        }
    }
    return true;
}

bool InputValidation::checkFirstAndLastSeparator()
{
    if (substring[0] == '|') return false;
    else if (std::count(substring.begin(), substring.end(), '|') <= 9 && substring[substring.size() - 1] != '|') return false;
    else if (std::count(substring.begin(), substring.end(), '|') == 10 && substring[substring.size() - 1] == '|') return false;
    else return true;
}

bool InputValidation::checkInputData()
{
    if (checkAllChars() &&
        checkNumberofFrames() &&
        isPlayerNameCorrect &&
        checkFirstAndLastSeparator())
    {
        for (int i = 0; i < substring.size(); i++)
        {
            if (substring[i] == '|' && i != 0)
            {
                switch (substring[i - 1])
                {
                case 'x':
                    if (!checkStrike(i)) return false;
                    break;

                case '-':
                    if (!checkSpareOrMiss(i)) return false;
                    break;

                case'/':
                    if (!checkSpareOrMiss(i)) return false;
                    break;

                case '|':
                    if (!checkFrameSeparator(i)) return false;
                    break;

                default:
                    if (!checkNumberOfPinchedPins(i)) return false;
                    break;
                }
            }
        }
        return true;
    }
    else return false;
}

InputValidation::~InputValidation() {}
