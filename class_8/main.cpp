#include <cmath>
#include <iostream>

int viralAdvertising(int n) {
    int cumulative = 0;
    int users = 5;
    int likes = 0;
    for (int i = 0; i < n; i++){
        likes = std::floor(users*0.5);
        users = likes * 3;
        cumulative += likes;
    }
    return cumulative;
}

int main(){
    std::cout << viralAdvertising(5) << "\n";
    return 0;
}