#include <../inc/GameStatus.hpp>
#include <gtest/gtest.h>

struct GameStatusTest : public ::testing::Test
{};

TEST_F(GameStatusTest, 1_check_method_getStatus)
{
    // GIVEN
    std::string path("../results/Game4.txt");
    // WHEN
    Status status(path);
    // THEN
    ASSERT_EQ(status.getStatus(), "game finished");
}


