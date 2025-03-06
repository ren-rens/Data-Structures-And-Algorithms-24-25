#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

long long N, M;
std::unordered_map<long long, std::unordered_set<long long>> graph;
long long ivanchoIndex;

void input() {
    std::cin >> N >> M;
    
    for(long long i = 1; i < N; i++) {
        graph[i];
    }
    
    long long x1, x2;
    for(long long i = 0; i < M; i++) {
        std::cin >> x1 >> x2;
        
        graph[x1].insert(x2);
        graph[x2].insert(x1);
    }
    
    std::cin >> ivanchoIndex;
}

std::vector<long long> bfs(long long start) {
    std::vector<long long> distances(N + 1, -1);
    
    std::queue<long long> next;
    next.push(start);
    
    long long level = 0;
    
    std::unordered_set<long long> visited;
    visited.insert(start);
    
    while(!next.empty()) {
        long long levelSize = next.size();
        
        for(long long i = 0; i < levelSize; i++) {
            long long current = next.front();
            next.pop();
            
            distances[current] = level * 6;
            
            for(const auto& nb : graph[current]) {
                if(visited.count(nb) != 0) {
                    continue;
                }
                
                visited.insert(nb);
                next.push(nb);
            }
        }
        
        level++;
    }
    
    return distances;
}

void solve() {
    std::vector<long long> distances = bfs(ivanchoIndex);
    
    for(long long i = 1; i < distances.size(); i++) {
        if(distances[i] == 0) {
            continue;
        }
        
        std::cout << distances[i] << ' ';
    }
    
    std::cout << '\n';
}
int main() {
    long long Q;
    std::cin >> Q;
    
    for(long long i = 0; i < Q; i++) {
        graph.clear();
        input();
        
        solve();
    }
    
    return 0;
}
