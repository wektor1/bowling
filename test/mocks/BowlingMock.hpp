#include "../../inc/Bowling.hpp"
#include "gmock/gmock.h"


struct BowlingWithNumberOfGames :public Bowling
{
    BowlingWithNumberOfGames(const std::string& path) : Bowling(path) {}
    int getGamesNumber()
    {
        return getGamesList().size();
    }
    ~BowlingWithNumberOfGames(){}
};
