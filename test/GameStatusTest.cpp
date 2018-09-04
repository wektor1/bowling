#include <../inc/GameStatus.hpp>
#include <gtest/gtest.h>

struct GameStatusTest : public ::testing::Test
{};

TEST_F(GameStatusTest, 1_check_method_getStatus)
{
    // GIVEN
    std::string path("../results/Game1.txt");
    // WHEN
    Status status(path);
    // THEN
    ASSERT_EQ(status.getStatus(), "game in progress");
}

TEST_F(GameStatusTest, 2_check_method_getStatus)
{
    // GIVEN
    std::string path("../results/Game2.txt");
    // WHEN
    Status status(path);
    // THEN
    ASSERT_EQ(status.getStatus(), "game in progress");
}

TEST_F(GameStatusTest, 3_check_method_getStatus)
{
    // GIVEN
    std::string path("../results/Game3.txt");
    // WHEN
    Status status(path);
    // THEN
    ASSERT_EQ(status.getStatus(), "no game");
}

TEST_F(GameStatusTest, 4_check_method_getStatus)
{
    // GIVEN
    std::string path("../results/Game4.txt");
    // WHEN
    Status status(path);
    // THEN
    ASSERT_EQ(status.getStatus(), "game finished");
}

TEST_F(GameStatusTest, 5_check_method_getStatus)
{
    // GIVEN
    std::string path("../results/Game5.txt");
    // WHEN
    Status status(path);
    // THEN
    ASSERT_EQ(status.getStatus(), "no game");
}

TEST_F(GameStatusTest, 6_check_method_getStatus)
{
    // GIVEN
    std::string path("../results/Game10.txt");
    // WHEN
    Status status(path);
    // THEN
    ASSERT_EQ(status.getStatus(), "Can not open the file: ../results/Game10.txt");
}


