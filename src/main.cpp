#include <iostream>
#include <../inc/InputValidation.hpp>
#include <../inc/GameStatus.hpp>

int main()
{
    // GIVEN
    std::vector<std::string> results{"Mike:3-|5/|9-|--|x|",
                                     "Peter:x|2/|--|--|4"};
    // WHEN
    Status status(results);
    // THEN
    std::cout<<status.getStatus()<<std::endl;
    return 0;
}
