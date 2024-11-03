#include <iostream>

int main(){
    std::string input = "aasjhdjdkkkkjdd";
    int repeated;
    for(int i = 0; i < input.size(); i++){
        if(input[i+1] == input[i]) repeated++;
        else std::cout << input[i] << repeated << " ", repeated = 1;
    }
    return 0;
}