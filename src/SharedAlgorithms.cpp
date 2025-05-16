#include "SharedAlgorithms.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

SharedAlgorithms::SharedAlgorithms(){}

void SharedAlgorithms::sortData(std::vector<int>& vec){
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a < b;
    });
}

std::vector<int> SharedAlgorithms::subtractVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("Wektory muszą mieć tę samą długość.");
    }
    int a;
    std::vector<int> result(vec1.size());
    for (size_t i = 0; i < vec1.size(); ++i) {
        a = abs(vec1[i] - vec2[i]);
        result[i] = a;
    }
    return result;
}

std::map<int, int> SharedAlgorithms::generateMapKeysFromVector(const std::vector<int>& vec){
    std::map<int, int> myMap;
    std::for_each(vec.begin(), vec.end(), [&myMap](int key) {
        myMap[key] = 0; // Domyślna wartość to 0
    });
    return myMap;
}

std::vector<int> SharedAlgorithms::calcuateVectorDiff(const std::vector<int>& vec){

    std::vector<int> vec_diff;
    std::transform(vec.begin() + 1, vec.end(), vec.begin(), std::back_inserter(vec_diff),
                   [](int a, int b) { return a - b; });
    return vec_diff;
}

std::vector<std::vector<int>> SharedAlgorithms::calcuateMatrixDiff(const std::vector<std::vector<int>>& matrix){
    
    std::vector<std::vector<int>> matrix_diff;
    std::for_each(matrix.begin(), matrix.end(), [&](const std::vector<int>& vec) {
       matrix_diff.push_back(SharedAlgorithms::calcuateVectorDiff(vec));
    });

    return matrix_diff;
}