#include <iostream>

void swap(int &element_1, int &element_2){
    int temp = element_1;
    element_1 = element_2;
    element_2 = temp;
}

void selection_sort(std::vector<int> &vec){
    int n = vec.size();
    for (int i = 0; i < n; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if (vec[j] < vec[min]){
                min = j;
            }
        
        }
        if(min != i) swap(vec[i], vec[min]);
    }
}

int main(){
    std::vector<int> vec = {1,8,3,5,2,4,6,2};
    selection_sort(vec);
    for (auto i: vec){
        std::cout << i << "\n";
    }
    return 0;
}