#include <../inc/Exceptions.hpp>
#include <../inc/GameStatus.hpp>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <locale>

const std::string Status::gameInProgress = "game in progress";
const std::string Status::noGame = "no game";
const std::string Status::gameFinished = "game finished";

Status::Status(const std::vector<std::string> &allPlayersResults_)
    : allPlayersResults(allPlayersResults_)
{
    changeToLower();
}

void Status::changeToLower()
{
    std::for_each(allPlayersResults.begin(), allPlayersResults.end(),
                  [](std::string &line) {
                      std::for_each(line.begin(), line.end(), [](char &sign) {
                          sign = std::tolower(sign);
                      });
                  });
}

void Status::checkStrike(const std::string &result)
{
    if (result.size() == result.find_last_of('|') + 1)
        allPlayersStatus.push_back(gameInProgress);
    else if (result[result.find_last_of('|') + 1] == 'x')
        allPlayersStatus.push_back(gameFinished);
    else
        allPlayersStatus.push_back(gameInProgress);
}

void Status::checkSpare(const std::string &result)
{
    if (result.size() == result.find_last_of('|') + 1)
        allPlayersStatus.push_back(gameInProgress);
    else if (result.size() == result.find_last_of('|') + 2)
        allPlayersStatus.push_back(gameFinished);
}

bool Status::checkEmptyFile(const std::string &result)
{
    if (result == "")
    {
        allPlayersStatus.push_back(noGame);
        return true;
    }
    return false;
}

bool Status::checkIfGameIsInProggress(const std::string &result)
{
    if (std::count(result.begin(), result.end(), '|') < 11)
    {
        allPlayersStatus.push_back(gameInProgress);
        return true;
    }
    return false;
}

void Status::checkExtraBall(const std::string &result)
{
    switch (result[result.find_last_of('|') - 2])
    {
    case 'x':
        checkStrike(result);
        break;
    case '/':
        checkSpare(result);
        break;
    default:
        allPlayersStatus.push_back(gameFinished);
    }
}

void Status::fileAnalyzer(const std::string &result)
{
    if (checkEmptyFile(result))
        return;
    if (checkIfGameIsInProggress(result))
        return;
    checkExtraBall(result);
}

std::string Status::statusAnalyzer() const
{
    if (std::count(allPlayersStatus.begin(), allPlayersStatus.end(), noGame) == 1)
    {
        return noGame;
    }
    if (std::count(allPlayersStatus.begin(), allPlayersStatus.end(), gameInProgress) > 0)
    {
        return gameInProgress;
    }
    return gameFinished;
}

std::string Status::getStatus()
{
    for (auto x : allPlayersResults)
        fileAnalyzer(x);
    return statusAnalyzer();
}

Status::~Status() {}
