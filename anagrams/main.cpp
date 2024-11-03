#include <unordered_map>
#include <iostream>
#include <string>

bool anagram(std::string s, std::string t) {
    std::unordered_map<char,int> word1;

    for(auto i: s){
        word1[i]++;
    }

    for(auto i: t){
        word1[i]--;
    }

    for(auto i: word1){
        if(i.second){
            return false;
        }
    }
    return true;
}

int main(){
    std::vector<std::string> vec = {"ana", "ababa", "aaabb", "bbaaa", "jolin", "jolon", "ad", "a", "aan"};
    std::vector<std::string> res;
    while(vec.size()){
        bool success = 0;
        for(int i = 1; i < vec.size(); i++){
            if(anagram(vec[0], vec[i])){
                vec.erase(vec.begin() + i);
                i--;
                success = 1;
            }
        }
        if(success) res.push_back(vec[0]);
        vec.erase(vec.begin());
    }

    for(auto i: res){
        std::cout << i << "\n";
    }
}