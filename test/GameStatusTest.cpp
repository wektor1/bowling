#include <../inc/GameStatus.hpp>
#include <gtest/gtest.h>
#include <vector>
#include <string>

struct GameStatusTest : public ::testing::Test
{};

TEST_F(GameStatusTest, expect_game_in_progress_when_two_players_still_play)
{
    // GIVEN
    std::vector<std::string> results{"Mike:3-|5/|9-|--|x|",
                                     "Peter:x|2/|--|--|4"};
    // WHEN
    Status status(results);
    // THEN
    ASSERT_EQ(status.getStatus(), "game in progress");
}

TEST_F(GameStatusTest, expect_game_in_progress_when_three_players_still_play)
{
    // GIVEN
    std::vector<std::string> results{"Luke:--|32|11|--|x|x|",
                                     "Snow:x|1/|7-|x|-3|22|",
                                     "Billy:1-|4/|--|4/|--|5/|"};
    // WHEN
    Status status(results);
    // THEN
    ASSERT_EQ(status.getStatus(), "game in progress");
}

TEST_F(GameStatusTest, expect_no_game_when_there_is_an_empty_string)
{
    // GIVEN
    std::vector<std::string> results{""};
    // WHEN
    Status status(results);
    // THEN
    ASSERT_EQ(status.getStatus(), "no game");
}

TEST_F(GameStatusTest, expect_game_finished_when_all_players_finished_theirs_games)
{
    // GIVEN
    std::vector<std::string> results{"Lucky:x|x|x|x|x|x|x|x|x|x||x",
                                     "Kate:x|x|x|x|x|x|x|x|x|x||x"};
    // WHEN
    Status status(results);
    // THEN
    ASSERT_EQ(status.getStatus(), "game finished");
}
