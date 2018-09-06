#include <string>
#include <vector>
#include <fstream>

class Game
{
  private:
    std::string pathToFile;
    std::vector<std::string> playersResult;
    bool correctnessOfInputData;


    void checkInputData();
    void openFile(std::ifstream &inFile);
public:
    explicit Game(const std::string& pathToFile_);
    std::string getGameStatus();
};
