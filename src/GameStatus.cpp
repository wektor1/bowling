#include <../inc/GameStatus.hpp>
#include <../inc/Exceptions.hpp>
#include <fstream>
#include <iostream>
#include <algorithm>

Status::Status(const std::string& pathToGameFile) :
    path(pathToGameFile),
    status{ "game in progress","no game","game finished" }
{
}

Status::Status(const std::string& folder, const std::string& fileName) :
    Status("../" + folder + "/" + fileName + ".txt")
{
}

void Status::fileAnalyzer(const std::string& result)
{
    if (result == "")
    {
        allPlayersStatus.push_back(status[1]);
        return;
    }

    if (std::count(result.begin(), result.end(), '|') < 11)
        allPlayersStatus.push_back(status[0]);

    switch (result[result.find_last_of('|') - 2])
    {
    case 'x':
        if (result.size() == result.find_last_of('|') + 1)
            allPlayersStatus.push_back(status[0]);
        if (result[result.find_last_of('|') + 1] == 'x')
            allPlayersStatus.push_back(status[2]);
        else
            allPlayersStatus.push_back(status[0]);
        break;

    case '/':
        if (result.size() == result.find_last_of('|') + 1)
            allPlayersStatus.push_back(status[0]);
        if (result.size() == result.find_last_of('|') + 2)
            allPlayersStatus.push_back(status[2]);
        break;

    default:
        allPlayersStatus.push_back(status[2]);
    }
}

std::string Status::statusAnalyzer() const
{
    if (std::count(allPlayersStatus.begin(), allPlayersStatus.end(), status[1]) == 1) return status[1];
    if (std::count(allPlayersStatus.begin(), allPlayersStatus.end(), status[0]) >=
        std::count(allPlayersStatus.begin(), allPlayersStatus.end(), status[2])) return status[0];
    return status[2];
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
        else
        {
            throw InvalidFile(path);
        }
    }
    catch (InvalidFile& exception)
    {
        return exception.what();
    }
}

Status::~Status()
{
}
