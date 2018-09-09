#include "../inc/Bowling.hpp"
#include "mocks/BowlingMock.hpp"
#include <gtest/gtest.h>

struct BowlingTest : public testing::Test
{};

TEST_F(BowlingTest, iterating_through_files)
{
    //GIVEN
    std::string games_directory("../results");
    //WHEN
    BowlingWithNumberOfGames data(games_directory);
    //THEN
    ASSERT_EQ(data.getGamesNumber(),5);
}


