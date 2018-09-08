#pragma once
#include <string>

class ScoreCalculator
{
    int score, ball_score, ball_score_multiplier,
        second_ball_score_multiplier, third_ball_score_multiplier;
    std::string game;
    void isStrike(const char ball);
    void isMissed(const char ball);
    void isSpare(const char ball);
    void isNormalHit(const char ball);
    void checkCharacter(const char character, int &value);
    int calculatePoints(std::string::const_iterator begin,
                        std::string::const_iterator end);
    void endScore();

public:
    explicit ScoreCalculator(const std::string& game);
    ~ScoreCalculator();
    int getScore() const;
};
