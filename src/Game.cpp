#include <../inc/Game.hpp>
#include <../inc/GameStatus.hpp>
#include <../inc/InputValidation.hpp>
#include <../inc/ScoreInCompleted.hpp>
#include <../inc/Exceptions.hpp>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

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
    return "";
}

void Game::openFile()
{
    std::ifstream inFile(pathToFile);
    std::string oneLine;
    std::string test;
    if (inFile.is_open())
    {
    while (!inFile.eof())
    {
        std::getline(inFile, oneLine);
        std::stringstream ss(oneLine);
        std::getline(ss, test);
        //auto inputValidation = std::make_shared<InputValidation>(oneLine);
        InputValidation inputValidation(test);
        std::cout<<"status: "<<inputValidation.checkInputData()<<std::endl; //why 0 ?
        if(!(inputValidation.checkInputData()) && oneLine != "")
        {
            correctnessOfInputData = false;
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
