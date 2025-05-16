#pragma once

#include <vector>
#include <string>
#include <map>


  #ifdef __BUILD_WITH_LOGGER__

class SharedAlgorithms {
public:
    SharedAlgorithms();
    void sortData(std::vector<int>& vec);
    std::vector<int> subtractVectors(const std::vector<int>& vec1, const std::vector<int>& vec2);
    std::map<int, int> generateMapKeysFromVector(const std::vector<int>& vec);
    std::vector<int> calcuateVectorDiff(const std::vector<int>& vec);
    std::vector<std::vector<int>> calcuateMatrixDiff(const std::vector<std::vector<int>>& matrix);


};

#endif