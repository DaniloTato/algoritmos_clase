#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <vector>
#include <tuple>
#include <random>

#include "../include/header.hpp"

void swap(int& element_1, int& element_2){
    int save = element_1;
    element_1 = element_2;
    element_2 = save;
}

void print_vector(std::vector<int> &vec){
    std::cout << "[ ";
    for (auto i: vec){
        std::cout << i << ", ";
    }
    std::cout << " ]" << "\n";
}

template<typename T>
void clear_and_delete(std::vector<T> &vec){
    for(T i : vec){
        delete i;
    }
    vec.clear();
}

std::vector<int> generate_random_vector(int n, int min_value, int max_value) {
    std::vector<int> random_numbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min_value, max_value);

    for (int i = 0; i < n; ++i) {
        random_numbers.push_back(dist(gen));
    }

    return random_numbers;
}

#endif