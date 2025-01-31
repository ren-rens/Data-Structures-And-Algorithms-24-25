#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool numbers[10000000 + 1]{};

int main() {
    size_t N;
    std::cin >> N;
    
    for(size_t i = 0; i < N; i++) {
        int current;
        std::cin >> current;
        
        if(current > 0) {
            numbers[current] = true;
        }
    }
    
    size_t missingNumber = N + 1;
    for(size_t i = 1; i < N + 1; i++) {
        if(!numbers[i]) {
            missingNumber = i;
            break;
        }
    }
    std::cout << missingNumber;
}
