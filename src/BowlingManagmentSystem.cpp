#include <../inc/BowlingManagmentSystem.hpp>
#include <fstream>
#include <iostream>

BowlingManagmentSystem::BowlingManagmentSystem()
{
}

void BowlingManagmentSystem::aboutTheProject()
{
    std::cout<<"To display results on the screen enter: ./Bowling results\n";
    std::cout<<"To display results on the screen and save them enter: ./Bowling results <fileName.txt>\n";
    std::cout<<"For more information check: https://github.com/CodersSchool777/bowling\n";
}

void BowlingManagmentSystem::checkFirstGivenArgument(const std::string &firstArgument)
{
    if(firstArgument == "-h" || firstArgument == "--help")
    {
        aboutTheProject();
    }
    else
    {
        Bowling bowling("../" + firstArgument);
        std::cout<<bowling;
    }
}

void BowlingManagmentSystem::checkSecondGivenArgument(const std::string &firstArgument,
                                                      const std::string &secondArgument)
{
    Bowling bowling("../" + firstArgument);
    std::ofstream inFile("../save/" + secondArgument);
    inFile<<bowling;
    std::cout<<bowling;
}

void BowlingManagmentSystem::run(int argc, char* argv[])
{
    std::string firstArgument(argv[1]);                             //file direcory or help
    switch(argc)
    {
    case 2:
        checkFirstGivenArgument(firstArgument);
        break;
    case 3:
        std::string secondArgument(argv[2]);                        //optional file.txt
        checkSecondGivenArgument(firstArgument, secondArgument);
        break;
    }
}

BowlingManagmentSystem::~BowlingManagmentSystem()
{
}
