#include <string>
#include <vector>

class Game
{
  private:
    std::string pathToFile;
    std::vector<std::string> playersResult;
    bool correctnessOfInputData;


    void checkInputData();
    void openFile();
public:
    explicit Game(const std::string& pathToFile_);
    Game(const std::string& folder, const std::string& fileName);
    std::string getGameStatus();
};
