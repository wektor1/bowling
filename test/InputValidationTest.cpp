#include <../inc/InputValidation.hpp>
#include <gtest/gtest.h>

struct InputValidationTest : public ::testing::Test
{
};

TEST_F(InputValidationTest,
       check_if_substring_from_object_input_will_be_correct)
{
    // GIVEN
    InputValidation input("Player:x|--|4/|x|");
    // WHEN call gestSubstring method
    // THEN
    ASSERT_EQ("x|--|4/|x|", input.getSubstring());
}

TEST_F(InputValidationTest, expect_false_when_there_is_no_players_name)
{
    // GIVEN
    InputValidation input(":x|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_true_when_players_name_is_correct)
{
    // GIVEN
    InputValidation input("Mike:x|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_true_when_there_are_two_sticks_around_x)
{
    // GIVEN
    InputValidation input("Mike:|x|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_false_when_miss_is_before_strike)
{
    // GIVEN
    InputValidation input("Mike:-x|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_false_when_there_is_no_stick_after_two_signs)
{
    // GIVEN
    InputValidation input("Mike:x|--");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_true_when_there_are_is_stick_after_two_signs)
{
    // GIVEN
    InputValidation input("Mike:X|--|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_true_when_before_miss_is_correct_number)
{
    // GIVEN
    InputValidation input("Mike:x|5-|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_false_when_after_stirke_is_miss)
{
    // GIVEN
    InputValidation input("Mike:x|x-|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_false_when_spare_is_the_first_sign)
{
    // GIVEN
    InputValidation input("Mike:x|/-|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_false_when_two_sticks_are_too_early)
{
    // GIVEN
    InputValidation input("Mike:x||-|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_true_when_spare_is_after_miss)
{
    // GIVEN
    InputValidation input("Mike:x|6-|-/|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_false_when_there_is_number_less_then_one)
{
    // GIVEN
    InputValidation input("Mike:x|0-|-/|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_false_when_there_is_undefined_sign)
{
    // GIVEN
    InputValidation input("Mike:x|k-|-/|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_false_when_spare_is_after_strike)
{
    // GIVEN
    InputValidation input("Mike:x|--|x/|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, epect_false_when_spare_is_the_first_sign_in_frame)
{
    // GIVEN
    InputValidation input("Mike:x|--|//|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_true_when_spare_is_after_number_less_then_ten)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_false_when_sum_of_numbers_is_bigger_then_nine)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|19|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_true_when_sum_of_numbers_is_less_then_nine)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|X|-3|18|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_false_when_there_are_two_sticks_in_incorrect_place)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|X|-3|18|x|-3||");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_false_when_there_are_no_two_sticks_in_correct_place)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|--|");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_true_when_there_are_two_sticks_in_correct_place)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|--||");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_true_when_spare_is_before_two_sticks)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_true_when_there_is_strike_after_two_sticks_and_spare)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||x");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_true_when_there_is_one_miss_after_two_sticks_and_spare)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||-");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_true_when_there_is_number_after_two_sticks_and_spare)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||9");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_false_when_there_is_spare_after_two_sticks_and_spare)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||/");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_false_when_there_is_too_many_signs_after_two_sticks_and_spare)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|-/||5/");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_true_when_there_is_strike_after_two_sticks_and_strike)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||x");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_true_when_there_are_two_miss_after_two_sticks_and_strike)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||--");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(
    InputValidationTest,
    expect_true_when_there_are_2_numbers_which_sum_is_less_then_9_after_two_sticks_and_strike)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||17");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_false_when_there_is_spare_after_two_sticks_and_strike)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||/6");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest,
       expect_false_when_there_are_too_many_signs_after_strike)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||123");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_true_when_the_game_is_in_progress)
{
    // GIVEN
    InputValidation input("Mike:x|--|3");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_false_when_there_is_no_stick_after_strike)
{
    // GIVEN
    InputValidation input("Mike:x|--|x");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_false_when_there_is_only_spare_after_stick)
{
    // GIVEN
    InputValidation input("Mike:x|--|/");
    // WHEN call checkInputData method
    // THEN
    EXPECT_FALSE(input.checkInputData());
}

TEST_F(InputValidationTest, expect_true_when_the_game_is_not_finished)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||");
    // WHEN call checkInputData method
    // THEN
    EXPECT_TRUE(input.checkInputData());
}

TEST_F(InputValidationTest, check_if_player_name_is_correct)
{
    // GIVEN
    InputValidation input("Mike:x|--|9/|x|-3|18|x|-3|5/|x||/");
    // WHEN call checkInputData method
    // THEN
    ASSERT_EQ(input.getPlayerName(), "Mike");
}
