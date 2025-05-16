// src/main.cpp
#include <iostream>
#include "DataLoader.hpp"
#include "SharedAlgorithms.hpp"
#include <numeric>
#include <map>
#include <algorithm>



int main() {
    DataLoader dataloader("/home/mateusz/GIT/adventOfCode2024/input.txt");
    dataloader.loadMatrix();
    SharedAlgorithms sharedAlgorithms;
    std::vector<std::vector<int>> matrix_diff = sharedAlgorithms.calcuateMatrixDiff(dataloader.matrix);
    int counter = 0;
    bool isThresholdOK{false}, allPositive{false}, allNegative{false};
    std::for_each(matrix_diff.begin(), matrix_diff.end(), [&](const std::vector<int>& vec) {
       isThresholdOK = std::any_of(vec.begin(), vec.end(), [&](int val){
        return abs(val) > 3;
       });
       allPositive = std::any_of(vec.begin(), vec.end(), [&](int val){
        return val > 0;
       });
        allNegative = std::any_of(vec.begin(), vec.end(), [&](int val){
        return val < 0;
       });
        std::for_each(vec.begin(), vec.end(), [](int val) {
            std::cout << val << " "; // Wypisujemy każdy element
        });
        std::cout << "\n" << allPositive<< "\n" << allNegative<< "\n";
       counter += isThresholdOK && (allPositive || allNegative);


    });
    std::cout << counter << std::endl;
    return 0;
}

