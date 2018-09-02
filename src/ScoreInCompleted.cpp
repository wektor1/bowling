#include "../inc/ScoreInCompleted.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>

ScoreInCompleted::ScoreInCompleted(const std::string& game_) : game(game_)
{
    endScore();
}

ScoreInCompleted::~ScoreInCompleted() {}

int ScoreInCompleted::getScore() const { return score; }

void ScoreInCompleted::isStrike(const char ball)
{
    if (ball == 'x') {
        ball_score = 10;
        second_ball_score_multiplier++;
        third_ball_score_multiplier++;
    }
}

void ScoreInCompleted::isSpare(const char ball)
{
    if (ball == '/') {
        ball_score = 10 - ball_score;
        second_ball_score_multiplier++;
    }
}

void ScoreInCompleted::isMissed(const char ball)
{
    if (ball == '-')
        ball_score = 0;
}

void ScoreInCompleted::isNormalHit(const char ball)
{
    if (isdigit(ball))
        ball_score = std::atoi(&ball);
}

void ScoreInCompleted::checkCharacter(const char character, int &value)
{
    if (character != '|') {
        isSpare(character);
        isStrike(character);
        isMissed(character);
        isNormalHit(character);
        value += ball_score * ball_score_multiplier;
        ball_score_multiplier = second_ball_score_multiplier;
        second_ball_score_multiplier = third_ball_score_multiplier;
        third_ball_score_multiplier = 1;
    }
}

int ScoreInCompleted::calculatePoints(std::string::const_iterator begin,
                                      std::string::const_iterator end)
{
    int value = 0;
    ball_score_multiplier = third_ball_score_multiplier
        = second_ball_score_multiplier = 1;
    ball_score = 0;
    std::for_each(begin, end,
                  [&](const char ball) { checkCharacter(ball, value); });
    return value;
}

void ScoreInCompleted::endScore()
{
    score = calculatePoints(game.begin(), game.end());
    auto normal_frames_end = (game.end() - 2);
    score -= calculatePoints(normal_frames_end, game.end());
}
