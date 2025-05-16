#pragma once

#include <vector>
#include <string>

class DataLoader {
public:
    DataLoader(const std::string& filename);
    bool loadData();
    bool loadMatrix();
    void displayData(const std::string& prefix, const std::vector<int>& vec) const;
    std::vector<int> column1;
    std::vector<int> column2;
    std::vector<std::vector<int>> matrix;

private:
    std::string filename;
};
