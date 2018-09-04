#include <../inc/GameStatus.hpp>
#include <../inc/Exceptions.hpp>
#include <fstream>
#include <algorithm>

Status::Status(const std::string& pathToGameFile) :
    path(pathToGameFile)
{
}

Status::Status(const std::string& folder, const std::string& fileName) :
    Status("../" + folder + "/" + fileName + ".txt")
{
}

void Status::checkStrike(const std::string& result)
{
    if (result.size() == result.find_last_of('|') + 1)
        allPlayersStatus.push_back("game in progress");
    if (result[result.find_last_of('|') + 1] == 'x')
        allPlayersStatus.push_back("game finished");
    else
        allPlayersStatus.push_back("game in progress");
}

void Status::checkSpare(const std::string& result)
{
    if (result.size() == result.find_last_of('|') + 1)
        allPlayersStatus.push_back("game in progress");
    if (result.size() == result.find_last_of('|') + 2)
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

 void Status::checkIfGameIsInProggress(const std::string& result)
 {
     if (std::count(result.begin(), result.end(), '|') < 11)
     {
         allPlayersStatus.push_back("game in progress");
     }
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
    checkIfGameIsInProggress(result);
    checkExtraBall(result);
}

std::string Status::statusAnalyzer() const
{
    if (std::count(allPlayersStatus.begin(), allPlayersStatus.end(), "no game") == 1)
    {
        return "no game";
    }
    if (std::count(allPlayersStatus.begin(), allPlayersStatus.end(), "game in progress") >=
        std::count(allPlayersStatus.begin(), allPlayersStatus.end(), "game finished"))
    {
        return "game in progress";
    }
    return "game finished";
}

std::string Status::getStatus()
{
    std::string oneLine;
    std::ifstream inFile(path);
    try
    {
        if (inFile.is_open())
        {
            while (!inFile.eof())
            {
                std::getline(inFile, oneLine);
                fileAnalyzer(oneLine);
            }
            inFile.close();
            return statusAnalyzer();
        }
        else throw InvalidFile(path);
    }
    catch (InvalidFile& exception)
    {
        return exception.what();
    }
}

Status::~Status()
{
}
