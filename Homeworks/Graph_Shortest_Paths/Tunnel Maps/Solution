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
    int to, weight, time;
};

struct Node{
    int index, summary_time;
    
    bool operator<(const Node& other) const{
        return summary_time > other.summary_time;
    }
};

const size_t MAX = 1e5 + 5;
std::unordered_map<int, std::vector<Edge>> graph;
int junction_count, tunnels_count, battery_time;

void input( ){
    std::cin >> junction_count >> tunnels_count >> battery_time;

    for(int i = 0; i < tunnels_count; i++){
        int j1, j2, weight, time;
        std::cin >> j1 >> j2 >> weight >> time;
        
        graph[j1].push_back({j2, weight, time});
    }
}

bool dijkstra(int max_weight){
    int start = 1;
    
    std::priority_queue<Node> next_to_proccess;
    next_to_proccess.push({start, 0});
    
    std::vector<int> dist(MAX, INT_MAX);
    dist[start] = 0;
    
    while (!next_to_proccess.empty()) {
        Node curr = next_to_proccess.top();
        next_to_proccess.pop();

        if (curr.summary_time > dist[curr.index]){
            continue;
        } 

        for (auto &edge : graph[curr.index]) {
            if (edge.weight > max_weight){
                continue; 
            } 
            
            int newTime = curr.summary_time + edge.time;
            if (newTime < dist[edge.to]) {
                dist[edge.to] = newTime;
                next_to_proccess.push({edge.to, newTime});
            }
        }
    }

    return dist[junction_count] <= battery_time;
}
int binary_search(){
    int left = 1, right = 1e6, res = -1;
    
    while(left <= right){
        int mid = left + (right - left)/2;
        
        if(dijkstra(mid)){
            res = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */       
    input();
    
    std::cout << binary_search();
    
    return 0;
}
