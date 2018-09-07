#include <iostream>
#include <../inc/InputValidation.hpp>
#include <../inc/GameStatus.hpp>

int main()
{

        // GIVEN
        std::vector<std::string> results{"Mike:3-|5/|9-|--|x|",
                                         "Peter:x|2/|--|--|4",
                                        "Luke:--|32|11|--|x|x|",
                                        "Snow:x|1/|7-|x|-3|22|",
                                        "Billy:1-|4/|--|4/|--|5/|",
                                        "Lucky:x|x|x|x|x|x|x|x|x|--||",
                                        "Kate:x|x|x|x|x|x|x|x|x|-/||1"};
        // WHEN
        Status status(results);
        std::cout<<"elementow: "<<status.getAllPlayersStatus().size()<<std::endl;
        //for(auto x : status.getAllPlayersStatus()) std::cout<<x<<std::endl;
        std::cout<<"ostateczny status gry: "<<status.getStatus()<<std::endl;


    return 0;
}
