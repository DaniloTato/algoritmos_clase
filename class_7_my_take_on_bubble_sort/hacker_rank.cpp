#include <iostream>

void print_vector(std::vector<int> arr){
    std::cout << "[";
    for (auto i:arr){
        std::cout << i << ",";
    }
    std::cout << "]" << "\n";
}

int minimum_index(std::vector<int> &arr){
    int min_index = 0;

    for(int i = 0; i < arr.size(); i++){
        if (arr[i] < arr[min_index]) min_index = i;
    }
    return min_index;
}

int maximum_index(std::vector<int> &arr){
    int min_index = 0;

    for(int i = 0; i < arr.size(); i++){
        if (arr[i] > arr[min_index]) min_index = i;
    }
    return min_index;
}

void miniMaxSum(std::vector<int> &arr) {
    std::vector<int> copy = arr;

    long int suma_min = 0;
    for(int i = 0; i < 4; i++){
        int min_index = minimum_index(arr);
        suma_min += arr[min_index];
        arr.erase(arr.begin() + min_index);
    }

    long int suma_max = 0;
    for(int i = 0; i < 4; i++){
        int max_index = maximum_index(copy);
        suma_max += copy[max_index];
        copy.erase(copy.begin() + max_index);
    }

    std::cout << suma_min << " " << suma_max << "\n";
    
}

int main(){

    std::vector<int> vec = {1,2,4,6,8,9,2,4,6};
    miniMaxSum(vec);

    return 0;
}