#include <../inc/GameStatus.hpp>
#include <../inc/Exceptions.hpp>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <locale>

Status::Status(const std::vector<std::string>& allPlayersResults_) :
    allPlayersResults(allPlayersResults_)
{
    changeToLower();
}

void Status::changeToLower()
{
    std::for_each(allPlayersResults.begin(),allPlayersResults.end(),[](std::string& line)
    {
       std::for_each(line.begin(),line.end(),[](char& sign)
       {
           sign=std::tolower(sign);
       });
    });
}

void Status::checkStrike(const std::string& result)
{
    if (result.size() == result.find_last_of('|') + 1)
        allPlayersStatus.push_back("game in progress");
    else if (result[result.find_last_of('|') + 1] == 'x')
        allPlayersStatus.push_back("game finished");
    else
        allPlayersStatus.push_back("game in progress");
}

void Status::checkSpare(const std::string& result)
{
    if (result.size() == result.find_last_of('|') + 1)
        allPlayersStatus.push_back("game in progress");
    else if (result.size() == result.find_last_of('|') + 2)
        allPlayersStatus.push_back("game finished");
}

 bool Status::checkEmptyFile(const std::string& result)
 {
     if (result == "")
     {
         allPlayersStatus.push_back("no game");
         return true;
     }
     return false;
 }

 bool Status::checkIfGameIsInProggress(const std::string& result)
 {
     if (std::count(result.begin(), result.end(), '|') < 11)
     {
         allPlayersStatus.push_back("game in progress");
         return true;
     }
     return false;
 }

 void Status::checkExtraBall(const std::string& result)
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
         allPlayersStatus.push_back("game finished");
     }
 }

void Status::fileAnalyzer(const std::string& result)
{
    if (checkEmptyFile(result)) return;
    if (checkIfGameIsInProggress(result)) return;
    checkExtraBall(result);
}

std::string Status::statusAnalyzer() const
{
    if (std::count(allPlayersStatus.begin(), allPlayersStatus.end(), "no game") == 1)
    {
        return "no game";
    }
    if (std::count(allPlayersStatus.begin(), allPlayersStatus.end(), "game in progress") > 0)
    {
        return "game in progress";
    }
    return "game finished";
}

std::string Status::getStatus()
{
    for(auto x : allPlayersResults) fileAnalyzer(x);
    return statusAnalyzer();
}

Status::~Status()
{
}
