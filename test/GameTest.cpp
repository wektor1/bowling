#include <../inc/Game.hpp>
#include <gtest/gtest.h>
#include <string>

struct GameTest : public ::testing::Test
{
};

TEST_F(GameTest, check_if_game_status_from_Game1_will_be_correct)
{
    // GIVEN
    std::string pathtoFile("../results/Game1.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "game in progress");
}

TEST_F(GameTest, check_if_game_status_from_Game2_will_be_correct)
{
    // GIVEN
    std::string pathtoFile("../results/Game2.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "game in progress");
}

TEST_F(GameTest, check_if_Game3_is_an_empty_file)
{
    // GIVEN
    std::string pathtoFile("../results/Game3.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "no game");
}

TEST_F(GameTest, check_if_game_status_from_Game4_will_be_correct)
{
    // GIVEN
    std::string pathtoFile("../results/Game4.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "game finished");
}

TEST_F(GameTest, expect_warrning_after_loading_non_existent_file)
{
    // GIVEN
    std::string pathtoFile("../results/Game11.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getGameStatus(), "incorrect input");
}

TEST_F(GameTest, there_should_be_no_statistic_when_input_is_incorrect)
{
    // GIVEN
    std::string pathtoFile("../results/Game5.txt");
    // WHEN
    Game game(pathtoFile);
    // THEN
    ASSERT_EQ(game.getPlayersStatistic()["Ewa"], "");
}
