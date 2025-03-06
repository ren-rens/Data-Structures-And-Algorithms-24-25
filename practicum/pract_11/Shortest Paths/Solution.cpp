#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

struct Edge{
    long long to, weight;
};

struct Node{
    long long index, distance;
    
    bool operator<(const Node& other) const{
        return distance > other.distance;
    }
};

const long long DIV = 1e9 + 7;
long long N, M;
std::unordered_map<long long, std::vector<Edge>> graph;

void input(){
    std::cin >> N >> M;
    
    long long from, to, weight;
    for(long long i = 0; i < M; i++){
        std::cin >> from >> to >> weight;
        
        graph[from].push_back({to, weight});
    }
}

void print(const std::vector<long long>& dist, const std::vector<long long>& ways){
    if(dist[N] == LLONG_MAX){
        std::cout << -1 << ' ' << 0;
    }
    else{
        std::cout << dist[N] << ' ' << ways[N];
    }
}

void dijkstra(){
    std::priority_queue<Node> pq;
    pq.push({1, 0});
    
    std::vector<long long> dist(N + 1, LLONG_MAX);
    dist[1] = 0;
    
    std::vector<long long> ways(N + 1, 0);
    ways[1] = 1;
    
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        
        if(current.index == N){
            break;
        }
        
        if(current.distance > dist[current.index]){
            continue;
        }
        
        for(const auto& edge : graph[current.index]){
            long long new_weight = edge.weight + current.distance;
            
            if(new_weight < dist[edge.to]){
                dist[edge.to] = new_weight;
                ways[edge.to] = ways[current.index];
                
                pq.push({edge.to, new_weight});
            }
            else if(dist[edge.to] == dist[current.index] + edge.weight){
                ways[edge.to] = (ways[edge.to] + ways[current.index]) % DIV; 
            }
        }
    }
    
    print(dist, ways);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();

    dijkstra();
    
    return 0;
}
