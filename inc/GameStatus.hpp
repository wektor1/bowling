#pragma once
#include <string>
#include <vector>

class Status
{
private:
    std::vector<std::string> status;
    std::vector<std::string> allPlayersStatus;
    std::string path;
    void fileAnalyzer(const std::string& result);
    std::string statusAnalyzer() const;
public:
    explicit Status(const std::string& pathToGameFile);
    Status(const std::string& folder, const std::string& fileName);
    std::string getStatus();
    virtual ~Status();
};