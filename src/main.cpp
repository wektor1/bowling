#include <iostream>
#include <fstream>
#include <../inc/Bowling.hpp>


int main()
{
    Bowling* bowling = new Bowling("../results");
    std::cout<<*bowling;

    std::ofstream inFile("../save/Bowling.txt");
    inFile<<*bowling;

    delete bowling;
    return 0;
}
