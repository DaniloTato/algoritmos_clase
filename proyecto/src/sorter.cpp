#include "../include/header.hpp"

#include <iostream>
#include <vector>
#include <tuple>

sorter::sorter(){}

std::tuple<std::vector<int>*, std::vector<int>> sorter::next_step(){
    if(_i > _history.size() - 2){
        return {nullptr,{0}};
    }

    _i++;
    return {&_history[_i],_iterator_position[_i]};
}

void sorter::solve(std::vector<int> vec, void (sorter::*sorting_method)(std::vector<int>&, int, int)){
    _history = {};
    _i = 0;
    (this->*sorting_method)(vec, 0, vec.size() - 1);
}

void sorter::bubble_sort(std::vector<int> &vec, int useless, int useless2){
    int n = vec.size();
    int steps = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(vec[j] > vec[j+1]){
                swap(vec[j],vec[j+1]);
            }
            steps++;
            _history.push_back(vec);
            _iterator_position.push_back({j});
        }
    }
}

int sorter::partition(std::vector<int>& vec, int left, int right, int pivot) {
    while (left <= right) {
        while (vec[left] < pivot) left++;
        while (vec[right] > pivot) right--;

        if (left <= right) {
            swap(vec[left], vec[right]);
            left++;
            right--;
        }
        _history.push_back(vec);
        _iterator_position.push_back({left, right});
    }
    return left;
}

void sorter::quick_sort(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;

    int pivot = vec[(left + right) / 2];
    int index = partition(vec, left, right, pivot);

    quick_sort(vec, left, index - 1);
    quick_sort(vec, index, right);
}

void sorter::selection_sort(std::vector<int> &vec, int useless, int useless2){
    int n = vec.size();
    for (int i = 0; i < n; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if (vec[j] < vec[min]){
                min = j;
            }

            _history.push_back(vec);
            _iterator_position.push_back({i,j});
        
        }
        if(min != i) swap(vec[i], vec[min]);
        _history.push_back(vec);
        _iterator_position.push_back({i});
    }
}

int sorter::get_i(){
    return _i;
}

std::vector<std::vector<int>> sorter::get_history(){
    return _history;
}