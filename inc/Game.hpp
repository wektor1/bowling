#include <../inc/InputValidation.hpp>
#include <memory>
#include <string>
#include <vector>
#include <map>

class Game
{
  private:
    std::string pathToFile;
    std::vector<std::string> playersResult;
    std::multimap<int, std::string> playersStatisctic;
    bool correctnessOfInputData;
    void setGameStatistic(std::unique_ptr<InputValidation>& inputValidation, std::string& oneLine);
    void checkInputData();
    void openFile();
public:
    explicit Game(const std::string& pathToFile_);
    Game(const std::string& folder, const std::string& fileName);
    std::string getGameStatus();
    std::multimap<int, std::string> getPlayersStatistic(); //points and nicks
};
