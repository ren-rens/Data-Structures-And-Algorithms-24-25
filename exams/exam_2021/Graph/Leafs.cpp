#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

long long edges, queries;
std::unordered_map<long long, std::unordered_set<long long>> graph;

void input() {
    std::cin >> edges >> queries;
    
    long long from, to;
    for(long long i = 0; i < edges; i++) {
        std::cin >> from >> to;
        
        graph[from].insert(to);
    }
}

void dfs(long long current, std::unordered_set<long long>& visited, long long& summary) {
    visited.insert(current);
    
    for(const auto& nb : graph[current]) {
        if(visited.count(nb) != 0) {
            continue;
        }
        
        dfs(nb, visited, summary += nb);
    }
}

void solve(long long vertex) {
    std::unordered_set<long long> visited;
    long long summary = 0;
    
    dfs(vertex, visited, summary);
    
    std::cout << summary << '\n';
}

int main() {
    
    input();
    
    long long vertex;
    while(queries--) {
        std::cin >> vertex;
        
        solve(vertex);
    }
    
    return 0;
}
