#include <iostream>

void quickSort(std::vector<int>& vec, int left, int right) {
    if(left < right){
        int pivote = vec[right];
        for(int i = left; i < right; i++){
            int subject = vec[i];
            if(subject > pivote){
                vec.insert(vec.begin() + right + 1, vec[i]);
                vec.erase(vec.begin() + i);
                i--;
                right--;
            }
        }
        quickSort(vec, left, right - 1);
        quickSort(vec, right + 1, vec.size() - 1);
    }
}

int main() {
    std::vector<int> vec = {10, 12, 7, 8, 9, 1, 5, 43, 2, 45, 88, 11};
    quickSort(vec, 0, vec.size() - 1);

    for (int i : vec) std::cout << i << "\n";
    return 0;
}