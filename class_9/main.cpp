#include <iostream>

int times_found_in(std::vector<int> vec){
    int times = 0;
    for(auto i: vec){
        if(i >= 0) times++;
    }
    return times;
}

std::string angryProfessor(int k, std::vector<int> a) {
    if(times_found_in(a) >= k){
       return "YES"; 
    } else return "NO"; 

}

int main(){
    return 0;
}