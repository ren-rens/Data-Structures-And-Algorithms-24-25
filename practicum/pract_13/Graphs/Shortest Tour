#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

long long N, M, K;
std::unordered_map<long long, std::unordered_set<long long>> graph;

bool containsInSequnceAfter(long long element, std::vector<long long>& sequence, long long index) {
    for(long long i = index + 1; i < K; i++) {
        if(sequence[i] == element) {
            return true;
        }
    }
    
    return false;
}

long long findPath(long long start, long long target, std::vector<long long>& sequence, long long index){
    std::queue<long long> q;
    q.push(start);
    
    long long level = 0;
    
    std::unordered_set<long long> visited;
    visited.insert(start);
    
    while(!q.empty()) {
        long long size = q.size();
        
        for(long long i = 0; i < size; i++) {
            auto current = q.front();
            q.pop();
            
            if(current == target) {
                return level;
            }
            
            for(const auto& nb : graph[current]) {
                if(containsInSequnceAfter(nb, sequence, index)) {
                    continue;
                }
                if(visited.count(nb) != 0) {
                    continue;
                }
                
                visited.insert(nb);
                q.push(nb);
            } 
        }
        level++;
    }
    
    return -1;
}
 
int main() {
    
    std::cin >> N >> M;
    
    long long x1, x2;
    for(long long i = 0; i < M; i++) {
        std::cin >> x1 >> x2;
        
        graph[x1].insert(x2);
    }
    
    std::cin >> K;
    
    std::vector<long long> sequence(K);
    
    for(long long i = 0; i < K; i++) {
        std::cin >> sequence[i];
    }
    
    long long path = 0;
    for(long long i = 0; i < K - 1; i++) {
        long long currentPath = findPath(sequence[i], sequence[i + 1], sequence, i + 1);
        
        if(currentPath == -1) {
            path = -1;
            break;
        }
        path += currentPath;
    }
    
    std::cout << path;
    
    return 0;
}
