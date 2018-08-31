#include <iostream>
#include "../inc/Bowling.hpp"
#include<../inc/InputValidation.hpp>
int main()

{
    InputValidation check("|||||||||||");
    check.checkInputData();
    return 0;
}
