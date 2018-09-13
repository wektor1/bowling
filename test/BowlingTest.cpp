#include "../inc/Bowling.hpp"
#include <gtest/gtest.h>

struct BowlingTest : public testing::Test
{
};

TEST_F(BowlingTest, iterating_through_files)
{
    // GIVEN
    std::string games_directory("../results");
    // WHEN
    Bowling data(games_directory);
    // THEN
    ASSERT_EQ(data.getGamesList().size(), 5);
}

TEST_F(BowlingTest, wrong_directory_path)
{
    // GIVEN
    std::string games_directory("../resultssssss");
    // WHEN
    Bowling data(games_directory);
    // THEN
    ASSERT_EQ(data.getGamesList().size(), 0);
}
