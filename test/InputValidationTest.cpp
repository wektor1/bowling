#include <gtest/gtest.h>
#include <../inc/InputValidation.hpp>

struct InputValidationTest : public ::testing::Test
{};

TEST_F(InputValidationTest, check_method_getSubstring)
{
    //GIVEN
    InputValidation input("Player:x|--|4/|x|");
    //WHEN call gestSubstring method
    //THEN
    ASSERT_EQ("x|--|4/|x|", input.getSubstring());
}

TEST_F(InputValidationTest, 1_check_method_checkInputData)
{
    //GIVEN
    InputValidation input(":x|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 2_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 3_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:|x|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 4_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:-x|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 5_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 6_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 7_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|5-|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 8_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|x-|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 9_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|/-|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 10_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x||-|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 11_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|6-|-/|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 12_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|0-|-/|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 13_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|k-|-/|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 14_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|x/|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 15_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|//|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 16_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 17_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|19|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 18_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 19_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3||");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 20_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|--|");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 21_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|--||");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 22_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 23_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||x");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 24_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||-");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 25_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||9");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 26_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||/");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 27_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||5/");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 28_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||x");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 29_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||--");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 30_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||17");
    //WHEN call checkInputData method
    //THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, 31_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||/6");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, 32_check_method_checkInputData)
{
    //GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||123");
    //WHEN call checkInputData method
    //THEN
    EXPECT_FALSE(input.checkInputData());
}



































































