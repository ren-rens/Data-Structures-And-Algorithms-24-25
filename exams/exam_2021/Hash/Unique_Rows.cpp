#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    long long N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<long long>> matrix(N, std::vector<long long>(M));
    
    for(long long i = 0; i < N; i++) {
        for(long long j = 0; j < M; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    std::unordered_map<std::string, long long> map; // key - row, value - count
    
    for(long long i = 0; i < N; i++) {
        std::string currentRow;
        
        for(long long j = 0; j < M; j++) {
            currentRow += matrix[i][j];
        }
        
        map[currentRow]++;        
    }
    
    
    long long count = 0;
    for(const auto& row : map) {
        if(row.second == 1) {
            count++;
        }
    }
    
    std::cout << count;
    
    return 0;
}
