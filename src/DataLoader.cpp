#include "DataLoader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

DataLoader::DataLoader(const std::string& filename) : filename(filename) {}

bool DataLoader::loadData() {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
        return false;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int num1, num2;

        if (iss >> num1 >> num2) {
            column1.push_back(num1);
            column2.push_back(num2);
        }
    }

    file.close();
    return true;
}

bool DataLoader::loadMatrix() {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
        return false;
    }
    while (std::getline(file, line)) {
        std::istringstream iss(line); // Strumień do przetwarzania linii
        std::vector<int> row; // Wektor do przechowywania pojedynczego rowa

        int number;
        // Wczytaj liczby z linii
        while (iss >> number) {
            row.push_back(number);
        }

        // Dodaj row do matrixy
        matrix.push_back(row);
    }

    file.close();
    return true;
}

void DataLoader::displayData(const std::string& prefix, const std::vector<int>& vec) const {
    std::cout << prefix;
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
