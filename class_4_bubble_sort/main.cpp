#include <iostream>

void swap(std::vector<int> &vec, int element_1, int element_2){
    int save = vec[element_1];
    vec[element_1] = vec[element_2];
    vec[element_2] = save;
}

std::array<int,2> bubble_sort(std::vector<int> &vec){
    int n = vec.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(vec[j] > vec[j+1]){
                swap(vec,j,j+1);
            }
        }
    }
    return {vec[0],vec[vec.size()-1]};
}

int main(){
    std::vector<int> vec;
    int res;
    for (int i = 0; i < 7; i++){
        std::cout << "Calificación " << i << ":" << "\n";
        std::cin >> res;
        vec.push_back(res);
    }

    std::array<int,2> max_min = bubble_sort(vec);
    for (auto i: vec){
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << max_min[0] << "<- Minimo\n";
    std::cout << max_min[1] << "<- Maximo\n";
    return 0;
}