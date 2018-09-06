#include <iostream>
#include <../inc/InputValidation.hpp>

int main()
{
    InputValidation inputValidation("Mike:3-|5/|9-|--|x|");
    std::cout<<"Status z maina: "<<inputValidation.checkInputData()<<std::endl;
    return 0;
}
