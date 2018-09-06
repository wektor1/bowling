#include <iostream>
#include <memory>
#include <string>
#include <../inc/Bowling.hpp>
#include <../inc/InputValidation.hpp>
#include <../inc/Game.hpp>

int main()
{
   // auto inputValidation = std::make_unique<InputValidation>("Mike:3-|5/|9-|--|x|");
   // std::cout<<inputValidation->checkInputData()<<std::endl;

    // GIVEN
    std::string pathtoFile("../results/Game1.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    std::cout<<game.getGameStatus()<<std::endl;
    return 0;
}
