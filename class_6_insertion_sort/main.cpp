#include <iostream>

void insertion_sort(std::vector<int> &vec){
    int n = vec.size();

    for (int i = 1; i < n; i++){
        int key = vec[i];
        int j = i - 1;
        while(j>=0 && vec[j] > key){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}

bool is_it_prime(int num){
    for (int i = 2; i < num - 1; i++){
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

std::vector<int> filtrate_prime(std::vector<int> &vec){
    std::vector<int> new_vec;
    for(auto i : vec){
        if(is_it_prime(i)) new_vec.push_back(i);
    }
    return new_vec;
}

int main(){
    std::vector<int> vec = {17,7,4,9,4,6,9,4,3,2,1};
    std::vector<int> prime_vec = filtrate_prime(vec);
    insertion_sort(prime_vec);

    int errors = 0;
    for (auto i: prime_vec){
        std::cout << i << "\n";
        if(!is_it_prime(i)) errors++;
    }

    if(errors) std::cout << "errors happened" << "\n";

    // std::cout << is_it_prime(8) << "\n";

    return 0;
}