#include "../../inc/Bowling.hpp"
#include "gmock/gmock.h"


struct BowlingWithNumberOfGames :public Bowling
{
    explicit BowlingWithNumberOfGames(const std::string& path) : Bowling(path) {}
    int getGamesNumber()
    {
        return getGamesList().size();
    }
    ~BowlingWithNumberOfGames(){}
};
