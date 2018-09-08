#include <../inc/Game.hpp>
#include <gtest/gtest.h>
#include <string>

struct GameTest : public ::testing::Test
{};

TEST_F(GameTest, 1_check_method_getGameStatus)
{
    // GIVEN
    std::string pathtoFile("../results/Game1.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "game in progress");
}

TEST_F(GameTest, 2_check_method_getGameStatus)
{
    // GIVEN
    std::string pathtoFile("../results/Game2.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "game in progress");
}

TEST_F(GameTest, 3_check_method_getGameStatus)
{
    // GIVEN
    std::string pathtoFile("../results/Game3.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "no game");
}

TEST_F(GameTest, 4_check_method_getGameStatus)
{
    // GIVEN
    std::string pathtoFile("../results/Game4.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "game finished");
}

TEST_F(GameTest, 5_check_method_getGameStatus)
{
    // GIVEN
    std::string pathtoFile("../results/Game11.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "");
}

TEST_F(GameTest, 6_check_method_getPlayersStatistic)
{
    // GIVEN
    std::string pathtoFile("../results/Game5.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getPlayersStatistic()["Ewa"], 90);
}

