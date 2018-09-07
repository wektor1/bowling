#include "../inc/ScoreCalculator.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>

ScoreCalculator::ScoreCalculator(const std::string& game_,const std::string& status_) : game(game_), status(status_)
{
    endScore();
}

ScoreCalculator::~ScoreCalculator() {}

int ScoreCalculator::getScore() const { return score; }

void ScoreCalculator::isStrike(const char ball)
{
    if (ball == 'x') {
        ball_score = 10;
        second_ball_score_multiplier++;
        third_ball_score_multiplier++;
    }
}

void ScoreCalculator::isSpare(const char ball)
{
    if (ball == '/') {
        ball_score = 10 - ball_score;
        second_ball_score_multiplier++;
    }
}

void ScoreCalculator::isMissed(const char ball)
{
    if (ball == '-')
        ball_score = 0;
}

void ScoreCalculator::isNormalHit(const char ball)
{
    if (isdigit(ball))
        ball_score = std::atoi(&ball);
}

void ScoreCalculator::checkCharacter(const char character, int &value)
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

int ScoreCalculator::calculatePoints(std::string::const_iterator begin,
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

void ScoreCalculator::endScore()
{
    score = calculatePoints(game.begin(), game.end());
    auto normal_frames_end = (game.end() - 2);
    if(status == "game finished")
    score -= calculatePoints(normal_frames_end, game.end());
}
