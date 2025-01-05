#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>
#include <unordered_set>


using namespace std;
struct Edge{
    int to, weight;
};
struct Node{
    int index, distance;
    
    bool operator<(const Node& other) const {
        return distance > other.distance;
    }
};

int N, M;
std::unordered_map<int, std::vector<Edge>> graph;
std::vector<int> Tnodes;

void input(){
    std::cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int v1, v2, weight;
        std::cin >> v1 >> v2 >> weight;
        
        graph[v1].push_back({v2, weight});
        graph[v2].push_back({v1, weight});
    }    
    
    int K;
    std::cin >> K;
    
    for(int i = 0; i < K; i++){
        int index;
        std::cin >> index;
        
        Tnodes.push_back(index);
    }
}

void dijkstra(std::vector<int>& dist, std::priority_queue<Node>& pq){
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        
        if(current.distance > dist[current.index]){
            continue;
        }
        
        for(const auto& edge : graph[current.index]){
            int new_dist = edge.weight + current.distance;
            
            if(new_dist < dist[edge.to]){
                dist[edge.to] = new_dist;
                pq.push({edge.to, new_dist});
            }
        }
    }
}

void solve(){
    std::vector<int> dist(N, INT_MAX);
    std::priority_queue<Node> pq;
    
    for(auto& t : Tnodes){
        dist[t] = 0;
        pq.push({t, 0});
    }
    
    dijkstra(dist, pq);
    
    int Q;
    std::cin >> Q;
    
    while(Q--){
        int query;
        std::cin >> query;
        
        std::cout << (dist[query] == INT_MAX? -1 : dist[query]) << std::endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    
    solve();
    
    return 0;                          
}
