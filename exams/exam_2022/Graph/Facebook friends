#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

long long N, E, K;
std::unordered_map<long long, std::unordered_set<long long>> graph;

void dfs(long long current, std::unordered_set<long long>& visited, long long& count) {
    visited.insert(current);
    
    for(const auto& nb : graph[current]) {
        if(visited.count(nb) != 0) {
            continue;
        }
        
        dfs(nb, visited, count+=1);
    }
}

long long solve() {
    std::unordered_set<long long> visited;
    long long count = 0;
    
    for(auto iter = graph.begin(); iter != graph.end(); iter++) {
        if(visited.count(iter->first) != 0) {
            continue;
        }
        
        long long vertexCount = 1;
        
        dfs(iter->first, visited, vertexCount);
        
        if(vertexCount % K == 0) {
            count++;
        }
    }
    
    return count;
}

int main() {
    std::cin >> N >> E >> K;
    
    for(long long i = 0; i < N; i++) {
        graph[i];
    }
    
    long long x, y;
    for(long long i = 0; i < E; i++) {
        std::cin >> x >> y;
        
        graph[x].insert(y);
        graph[y].insert(x);
    }
    
    std::cout << solve();
    
    return 0;
}
