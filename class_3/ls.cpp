#include <iostream>

int linear_search(std::vector<int> vec, int num){
    for (auto i : vec){
        if( i > num){
            return i;
        }
    }
    return -1;
}

int main(){
    std::vector<int> lista = {5, 2, 9, 7, 4, 6};
    int ref = 5;
    std::cout << linear_search(lista, ref) << "\n";
    return 0;
}