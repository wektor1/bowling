#include <../inc/Game.hpp>
#include <../inc/GameStatus.hpp>
#include <../inc/InputValidation.hpp>
#include <../inc/ScoreInCompleted.hpp>
#include <../inc/Exceptions.hpp>
#include <memory>
#include <iostream>
#include <fstream>

Game::Game(const std::string& pathToFile_) :
    pathToFile(pathToFile_),
    correctnessOfInputData(false)
{
}

Game::Game(const std::string& folder, const std::string& fileName) :
    Game("../" + folder + "/" + fileName + ".txt")
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
    return "";
}

void Game::openFile()
{
    std::ifstream inFile(pathToFile);
    std::string oneLine;
    if (inFile.is_open())
    {
    while (!inFile.eof())
    {
    	std::getline(inFile, oneLine, '\r');
        auto inputValidation = std::make_shared<InputValidation>(oneLine);
        if(!(inputValidation->checkInputData()) && oneLine != "")
        {
            throw IncorrectInputData(oneLine);
        }
        else playersResult.emplace_back(oneLine);
    }
    correctnessOfInputData = true;
    }
    else throw InvalidFile(pathToFile);
}

void Game::checkInputData()
{
    try
    {
        openFile();
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
