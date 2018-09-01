#include "../inc/ScoreInCompleted.hpp"
#include <gtest/gtest.h>

struct ScoreInCompletedTest : public ::testing::Test
{};

TEST_F(ScoreInCompletedTest, all_balls_missed)
{
    // GIVEN
    std::string game("--|--|--|--|--|--|--|--|--|--||");
    // WHEN
    ScoreInCompleted score(game);
    // THEN
    ASSERT_EQ(score.getScore(), 0);
}

TEST_F(ScoreInCompletedTest, strikes_in_all_frames)
{
    // GIVEN
    std::string game("x|x|x|x|x|x|x|x|x|x||xx");
    // WHEN
    ScoreInCompleted score(game);
    // THEN
    ASSERT_EQ(score.getScore(), 300);
}

TEST_F(ScoreInCompletedTest, spares_in_all_frames)
{
    {
        // GIVEN
        std::string game("-/|-/|-/|-/|-/|-/|-/|-/|-/|-/||-");
        // WHEN
        ScoreInCompleted score(game);
        // THEN
        ASSERT_EQ(score.getScore(), 100);
    }
    {
        // GIVEN
        std::string game("5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5");
        // WHEN
        ScoreInCompleted score(game);
        // THEN
        ASSERT_EQ(score.getScore(), 150);
    }
}

TEST_F(ScoreInCompletedTest, average_games)
{
    {
        // GIVEN
        std::string game("23|18|9/|2-|31|54|3/|x|7|14||");
        // WHEN called scoreInCompleted(game);
        ScoreInCompleted score(game);
        // THEN
        ASSERT_EQ(score.getScore(), 91);
    }
    {
        // GIVEN
        std::string game("x|7/|9-|x|-8|8/|-6|x|x|x||81");
        // WHEN
        ScoreInCompleted score(game);
        // THEN
        ASSERT_EQ(score.getScore(), 167);
    }
}
