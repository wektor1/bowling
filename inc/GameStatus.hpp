#pragma once
#include <string>
#include <vector>

class Status
{
private:
    std::vector<std::string> allPlayersStatus;
    std::string path;
    void fileAnalyzer(const std::string& result);
    void checkStrike(const std::string& result);
    void checkSpare(const std::string& result);
    void checkIfGameIsInProggress(const std::string& result);
    void checkExtraBall(const std::string& result);
    bool checkEmptyFile(const std::string& result);
    std::string statusAnalyzer() const;
public:
    explicit Status(const std::string& pathToGameFile);
    Status(const std::string& folder, const std::string& fileName);
    std::string getStatus();
    virtual ~Status();
};
