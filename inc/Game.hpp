#include <string>
#include <vector>
#include <map>

class Game
{
  private:
    std::string pathToFile;
    bool correctnessOfInputData;
    std::vector<std::string> playersResult;
    std::multimap<unsigned short, std::string> playerStatisctic;


    void checkInputData();
    void openFile();
public:
    explicit Game(const std::string& pathToFile_);
    Game(const std::string& folder, const std::string& fileName);
    std::string getGameStatus();
};
