#pragma once
#include <../inc/Bowling.hpp>
#include <string>

class BowlingManagmentSystem
{
private:
    static void aboutTheProject();
    static void checkFirstGivenArgument(const std::string &firstArgument);
    static void checkSecondGivenArgument(const std::string &firstArgument,
                                         const std::string &secondArgument);
public:
    BowlingManagmentSystem();
    static void run(int argc, char* argv[]);
    virtual ~BowlingManagmentSystem();
};
