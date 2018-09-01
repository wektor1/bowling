#include "../inc/ScoreInCompleted.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>

ScoreInCompleted::ScoreInCompleted(std::string game) : game_(game)
{
    endScore();
}

ScoreInCompleted::~ScoreInCompleted() {}

int ScoreInCompleted::getScore() const { return score_; }

void ScoreInCompleted::isStrike(const char ball)
{
    if (ball == 'x') {
        ball_score_ = 10;
        second_ball_score_multiplier_++;
        third_ball_score_multiplier_++;
    }
}

void ScoreInCompleted::isSpare(const char ball)
{
    if (ball == '/') {
        ball_score_ = 10 - ball_score_;
        second_ball_score_multiplier_++;
    }
}

void ScoreInCompleted::isMissed(const char ball)
{
    if (ball == '-')
        ball_score_ = 0;
}

void ScoreInCompleted::isNormalHit(const char ball)
{
    if (isdigit(ball))
        ball_score_ = std::atoi(&ball);
}

void ScoreInCompleted::checkCharacter(const char character, int &value)
{
    if (character != '|') {
        isSpare(character);
        isStrike(character);
        isMissed(character);
        isNormalHit(character);
        value += ball_score_ * ball_score_multiplier_;
        ball_score_multiplier_ = second_ball_score_multiplier_;
        second_ball_score_multiplier_ = third_ball_score_multiplier_;
        third_ball_score_multiplier_ = 1;
    }
}

int ScoreInCompleted::calculatePoints(std::string::const_iterator begin,
                                      std::string::const_iterator end)
{
    int value = 0;
    ball_score_multiplier_ = third_ball_score_multiplier_
        = second_ball_score_multiplier_ = 1;
    ball_score_ = 0;
    std::for_each(begin, end,
                  [&](const char ball) { checkCharacter(ball, value); });
    return value;
}

void ScoreInCompleted::endScore()
{
    score_ = calculatePoints(game_.begin(), game_.end());
    auto normal_frames_end = (game_.end() - 2);
    score_ -= calculatePoints(normal_frames_end, game_.end());
}
