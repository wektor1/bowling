#include <../inc/Game.hpp>
#include <gtest/gtest.h>
#include <string>

struct GameTest : public ::testing::Test
{};

TEST_F(GameTest, 1_check_method_getGameStatus)
{
    // GIVEN
    std::string pathtoFile{"../results/game1.txt"};
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "game in progress");
}

TEST_F(GameTest, 2_check_method_getGameStatus)
{
    // GIVEN
    std::string pathtoFile{"../results/game2.txt"};
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "game in progress");
}

TEST_F(GameTest, 3_check_method_getGameStatus)
{
    // GIVEN
    std::string pathtoFile{"../results/game3.txt"};
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "no game");
}

TEST_F(GameTest, 4_check_method_getGameStatus)
{
    // GIVEN
    std::string pathtoFile{"../results/game4.txt"};
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "game finished");
}


