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

        int strike = 0;
        int tmo_diff;
        isThresholdOK = std::all_of(vec.begin(), vec.end(), [&](int val){
            bool result = true;
            if (abs(val) <= 3){
                result = true;
            }
            else{
                strike++;
                tmp_diff = val;
                if (strike<=1){
                    result = true;
                }
                else{
                    result = false;
                }
            }
            return result;
        });
        allPositive = std::all_of(vec.begin(), vec.end(), [&](int val){
            bool result = true;
            if (val > 0){
                result = true;
            }
            else{
                strike++;
                if (strike<=1){
                    result = true;
                }
                else{
                    result = false;
                }
            }
            return result;
        });
        allNegative = std::all_of(vec.begin(), vec.end(), [&](int val){
            bool result = true;
            if (val < 0){
                result = true;
            }
            else{
                strike++;
                if (strike<=1){
                    result = true;
                }
                else{
                    result = false;
                }
            }
            return result;
        });
        std::for_each(vec.begin(), vec.end(), [](int val) {
            std::cout << val << " "; // Wypisujemy każdy element
        });
        
        std::cout << "\n" << allPositive<< "\t" << isThresholdOK<< "\t" << allNegative<< "\n";
        
        counter += isThresholdOK && (allPositive || allNegative);


    });
    std::cout << counter << std::endl;
    return 0;
}

