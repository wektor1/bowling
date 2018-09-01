#pragma once
#include <string>

class ScoreInCompleted
{
    int score_, ball_score_, ball_score_multiplier_,
        second_ball_score_multiplier_, third_ball_score_multiplier_;
    std::string game_;
    void isStrike(const char ball);
    void isMissed(const char ball);
    void isSpare(const char ball);
    void isNormalHit(const char ball);
    void checkCharacter(const char character, int &value);
    int calculatePoints(std::string::const_iterator begin,
                        std::string::const_iterator end);
    void endScore();

public:
    ScoreInCompleted(const std::string game);
    ~ScoreInCompleted();
    int getScore() const;
};
