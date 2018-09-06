#include <../inc/Game.hpp>
#include <../inc/GameStatus.hpp>
#include <../inc/InputValidation.hpp>
#include <../inc/ScoreInCompleted.hpp>
#include <../inc/Exceptions.hpp>
#include <memory>
#include <iostream>


Game::Game(const std::string& pathToFile_) :
    pathToFile(pathToFile_)
{
}

std::string Game::getGameStatus()
{
    checkInputData();
    if(correctnessOfInputData)
    {
    auto gameStatus = std::make_unique<Status>(playersResult);
    return gameStatus->getStatus();
    }
    return "Incorrect format of input data";
}

void Game::openFile(std::ifstream& inFile)
{
    std::string oneLine;
    while (!inFile.eof())
    {
        std::getline(inFile, oneLine);
        auto inputValidation = std::make_unique<InputValidation>(oneLine);
        if(!inputValidation->checkInputData())
        {
            correctnessOfInputData = false;
            throw IncorrectInputData(oneLine);
        }
        else playersResult.emplace_back(oneLine);
    }
    correctnessOfInputData = true;
}

void Game::checkInputData()
{
    std::ifstream inFile(pathToFile);
    try
    {
        if (inFile.is_open()) openFile(inFile);
        else throw InvalidFile(pathToFile);
    }
    catch (InvalidFile& exception)
    {
        std::cout<<exception.what()<<std::endl;
    }
    catch (IncorrectInputData& exception)
    {
        std::cout<<exception.what()<<std::endl;
    }
}
