#include "../inc/Bowling.hpp"
#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

Bowling::Bowling(const std::string &files_directory_path)
{
    gamesLoader(files_directory_path);
}

void Bowling::gamesLoader(const std::string& directory)
{
    boost::filesystem::path directory_path(directory);
    boost::filesystem::directory_iterator itr(directory_path), end_itr;
    BOOST_FOREACH(boost::filesystem::path const& file, std::make_pair(itr,end_itr))
    {
        if(boost::filesystem::is_regular_file(file))
            games_list.push_back(Game(file.string()));
    }

}

std::vector<Game> Bowling::getGamesList()
{
    return games_list;
}

Bowling::~Bowling()
{
}
