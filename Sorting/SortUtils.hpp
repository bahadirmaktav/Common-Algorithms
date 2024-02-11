#ifndef SORT_UTILS_HPP_
#define SORT_UTILS_HPP_

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

class SortUtils {
public:
    static void PrintInputList(std::string title, std::vector<int>& input_list) {
        std::cout << title << " : ";
        for (int value : input_list) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    static void GenerateInputList(std::vector<int>& input_list, size_t size) {
        // Initialize vector which contains n=size elements 1 to n
        for (size_t i = 1; i <= size; ++i) {
            input_list.push_back(i);
        }
        // Shuffle the vector
        std::random_device rd;
        std::mt19937 mt(rd());
        std::shuffle(input_list.begin(), input_list.end(), mt);
    }
};

#endif // SORT_UTILS_HPP_