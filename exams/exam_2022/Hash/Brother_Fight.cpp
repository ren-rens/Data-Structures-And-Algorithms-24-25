#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long solve(std::vector<long long>& Ivan, std::vector<long long>& brother, long long N) {
    std::unordered_map<long long, long long> stickers;
    long long days = 0;
    
    for(long long i = 0; i < N; i++) {
        stickers[Ivan[i]]++;
        
        if(stickers.count(brother[i]) == 0) {
            days++;
        }
        else {
            stickers[brother[i]]--;
            if(stickers[brother[i]] == 0) {
                stickers.erase(brother[i]);
            }
        }
    }
    
    return days;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long N;
    std::cin >> N;
    
    std::vector<long long> Ivan(N);
    for(long long i = 0; i < N; i++) {
        std::cin >> Ivan[i];
    }
    
    std::vector<long long> brother(N);
    for(long long i = 0; i < N; i++) {
        std::cin >> brother[i];
    }
    
    std::cout << solve(Ivan, brother, N);
    
    return 0;
}
