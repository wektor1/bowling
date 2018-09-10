#pragma once
#include <../inc/Game.hpp>
#include <vector>
#include <string>

class Bowling
{
    std::vector<Game> games_list;
    void gamesLoader(const std::string& path);
public:
    explicit Bowling(const std::string& files_directory_path);
    std::vector<Game> getGamesList() const;
    void showAllResults();
    ~Bowling();
};
