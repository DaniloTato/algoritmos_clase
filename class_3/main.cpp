#include<iostream>

//complejidad O(n)
int binary_search(std::vector<int> vec, int target){
    int low = 0;
    int high = vec.size() - 1;
    int mid = high;
    if (vec[0] == target) return 0;
    while (vec[mid] != target){
        mid = (high + low) * 0.5;
        if (mid == low) return -1;
        vec[mid] <= target ? low = mid : high = mid;
    }
    return mid;

}

int main(){
    std::vector<int> vec = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78}; 
    int target = 12;
    std::cout << binary_search(vec, target) << "\n";
    return 0;
}
