#include <iostream>
#include <../inc/Bowling.hpp>


int main()
{
    Bowling* bowling = {new Bowling("../results")};
    bowling->showAllResults();

    delete bowling;
    return 0;
}
