#define BOOST_FILESYSTEM_NO_DEPRECATED
#include "../inc/Bowling.hpp"
#include "../inc/Exceptions.hpp"
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

Bowling::Bowling(const std::string &files_directory_path)
{
    try
    {
        gamesLoader(files_directory_path);
    }
    catch (const std::exception &except)
    {
        std::cout << except.what() << std::endl;
    }
}

void Bowling::gamesLoader(const std::string &directory)
{
    boost::filesystem::path directory_path(directory);
    boost::filesystem::directory_iterator itr(directory_path), end_itr;
    BOOST_FOREACH (const boost::filesystem::path &file,
                   std::make_pair(itr, end_itr))
    {
        if (boost::filesystem::is_regular_file(file))
            games_list.push_back(Game(file.string()));
    }
}

std::vector<Game> Bowling::getGamesList() const { return games_list; }

std::ostream &operator<<(std::ostream &os, const Bowling &bg)
{
    int lane = 1;
    for (auto &game : bg.getGamesList())
    {
        std::string showGameStatus = "### Lane " + std::to_string(lane) + ": "
                                     + game.getGameStatus() + " ###";
        os << showGameStatus << std::endl;
        if (showGameStatus.find("no game") == std::string::npos)
        {
            for (auto &stats : game.getPlayersStatistic())
            {
                os << stats.first << " " << stats.second << std::endl;
            }
        }
        lane++;
    }
    return os;
}

Bowling::~Bowling() {}
