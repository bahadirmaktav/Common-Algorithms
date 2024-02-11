#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include "MergeSort.hpp"

#define INPUT_LIST_SIZE 100

void GenerateInputList(std::vector<int>& input_list, size_t size);
void PrintInputList(std::string title, std::vector<int>& input_list);

int main() {
    std::vector<int> input_list;
    GenerateInputList(input_list, INPUT_LIST_SIZE);
    PrintInputList("Unsorted", input_list);
    MergeSort merge_sort;
    merge_sort.Sort(input_list);
    PrintInputList("Sorted", input_list);
}

void GenerateInputList(std::vector<int>& input_list, size_t size) {
    // Initialize vector which contains n=size elements 1 to n
    for (size_t i = 1; i <= size; ++i) {
        input_list.push_back(i);
    }
    // Shuffle the vector
    std::random_device rd;
    std::mt19937 mt(rd());
    std::shuffle(input_list.begin(), input_list.end(), mt);
}

void PrintInputList(std::string title, std::vector<int>& input_list) {
    std::cout << title << " : ";
    for (int value : input_list) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
