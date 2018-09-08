#include "../inc/ScoreCalculator.hpp"
#include <gtest/gtest.h>

struct ScoreCalculatorTest : public ::testing::Test
{};

TEST_F(ScoreCalculatorTest, all_balls_missed)
{
    // GIVEN
    std::string game("--|--|--|--|--|--|--|--|--|--||");
    // WHEN
    ScoreCalculator score(game);
    // THEN
    ASSERT_EQ(score.getScore(), 0);
}

TEST_F(ScoreCalculatorTest, strikes_in_all_frames)
{
    // GIVEN
    std::string game("x|x|x|x|x|x|x|x|x|x||xx");
    // WHEN
    ScoreCalculator score(game);
    // THEN
    ASSERT_EQ(score.getScore(), 300);
}

TEST_F(ScoreCalculatorTest, spares_in_all_frames)
{
    {
        // GIVEN
        std::string game("-/|-/|-/|-/|-/|-/|-/|-/|-/|-/||-");
        // WHEN
        ScoreCalculator score(game);
        // THEN
        ASSERT_EQ(score.getScore(), 100);
    }
    {
        // GIVEN
        std::string game("5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5");
        // WHEN
        ScoreCalculator score(game);
        // THEN
        ASSERT_EQ(score.getScore(), 150);
    }
}

TEST_F(ScoreCalculatorTest, average_games)
{
    {
        // GIVEN
        std::string game("23|18|9/|2-|31|54|3/|x|7|14||");
        // WHEN
        ScoreCalculator score(game);
        // THEN
        ASSERT_EQ(score.getScore(), 91);
    }
    {
        // GIVEN
        std::string game("x|7/|9-|x|-8|8/|-6|x|x|x||81");
        // WHEN
        ScoreCalculator score(game);
        // THEN
        ASSERT_EQ(score.getScore(), 167);
    }
}

TEST_F(ScoreCalculatorTest, unfinished_games)
{
    {
        //GIVEN
        std::string game("43|71|x|1/|-");
        //WHEN
        ScoreCalculator score(game);
        //THEN
        ASSERT_EQ(score.getScore(),45);
    }
    {
        //GIVEN
        std::string game("-3|1-|x|1/|-4|x|1");
        //WHEN
        ScoreCalculator score(game);
        //THEN
        ASSERT_EQ(score.getScore(),50);
    }
    {
        //GIVEN
        std::string game("x|x|x|x|-/|-");
        //WHEN
        ScoreCalculator score(game);
        //THEN
        ASSERT_EQ(score.getScore(),110);
    }
    {
        //GIVEN
        std::string game("41|42|-7|-/|x");
        //WHEN
        ScoreCalculator score(game);
        //THEN
        ASSERT_EQ(score.getScore(),48);
    }

}
