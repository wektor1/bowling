#include <../inc/Bowling.hpp>
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
    Bowling *bowling = new Bowling("../results");
    std::cout << *bowling;

    std::ofstream inFile("../save/Bowling.txt");
    inFile << *bowling;

    delete bowling;
    return 0;
}
