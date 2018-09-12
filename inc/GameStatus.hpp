#pragma once
#include <string>
#include <vector>

class Status
{
private:
    std::vector<std::string> allPlayersResults;
    std::vector<std::string> allPlayersStatus;
    void fileAnalyzer(const std::string& result);
    void checkStrike(const std::string& result);
    void checkSpare(const std::string& result);
    void checkExtraBall(const std::string& result);
    bool checkIfGameIsInProggress(const std::string& result);
    bool checkEmptyFile(const std::string& result);
    std::string statusAnalyzer() const;
    void changeToLower();
public:
    explicit Status(const std::vector<std::string>& allPlayersResults_);
    std::string getStatus();
    virtual ~Status();
};
