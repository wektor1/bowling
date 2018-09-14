#include <../inc/BowlingManagmentSystem.hpp>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
    try
    {
    BowlingManagmentSystem::run(argc, argv);
    }
    catch(...)
    {
    }
    return 0;
}
