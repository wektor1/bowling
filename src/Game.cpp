#include <../inc/Game.hpp>
#include <../inc/GameStatus.hpp>
#include <../inc/ScoreCalculator.hpp>
#include <../inc/Exceptions.hpp>
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
    return "incorrect input";
}

void Game::setGameStatistic(std::unique_ptr<InputValidation>& inputValidation, std::string& oneLine)
{
    auto score = std::make_unique<ScoreCalculator>(inputValidation->getSubstring());
    std::pair<std::string, std::string> pair;
    pair.first = inputValidation->getPlayerName();
    pair.second = std::to_string(score->getScore());
    playersStatisctic.insert(pair);
    playersResult.emplace_back(oneLine);
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
        inFile.get();
        auto inputValidation = std::make_unique<InputValidation>(oneLine);
        if(!(inputValidation->checkInputData()) && oneLine != "")
        {
            throw IncorrectInputData(oneLine);
        }
        else setGameStatistic(inputValidation, oneLine);
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
        std::cerr<<exception.what()<<std::endl;
    }
}

std::map<std::string, std::string> Game::getPlayersStatistic()
{
    checkInputData();
        if(correctnessOfInputData) return playersStatisctic;
        std::map<std::string, std::string> error;
        error.insert(std::pair<std::string, std::string>("", ""));
        return error;
}

Game::~Game()
{
}
