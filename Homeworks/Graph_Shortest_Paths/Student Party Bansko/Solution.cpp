#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <queue>
using namespace std;

const int MAX_SIZE = 1e4 + 2;
int intervals_of_time[MAX_SIZE];
int distances[MAX_SIZE];

std::unordered_map<int, int> graph[MAX_SIZE];

struct Node{
    int index, distance;
    
    bool operator<(const Node& other) const{
        return this->distance > other.distance;
    }
};

void input_graph(int E){
    for(int i = 0; i < E; i++){
        int s1, s2, time;
        std::cin >> s1 >> s2 >> time;
        if(graph[s1][s2] == 0){
            graph[s1][s2] = INT_MAX;
        }
        graph[s1][s2] = std::min(time, graph[s1][s2]);
    }
}

void input_distances(int V){
    for(int i = 0; i < V; i++){
        distances[i] = INT_MAX;
    }
}
int dijkstra(int V, int start, int end){
    input_distances(V);
    distances[start] = 0;
    
    std::priority_queue<Node> next_to_proccess;
    next_to_proccess.push({start, 0});
    
    while(!next_to_proccess.empty()){
        auto current = next_to_proccess.top();
        next_to_proccess.pop();
        
        if(current.index == end){
            return distances[end];
        }
        
        if(current.distance > distances[current.index]){
            continue;
        }
        
        
        for(auto& edge : graph[current.index]){
            int waiting_time = current.distance % intervals_of_time[current.index];
            int new_time = current.distance + edge.second;
            
            if(waiting_time != 0){
                new_time += (intervals_of_time[current.index] - waiting_time);
            }
            
            if(distances[edge.first] > new_time){
                distances[edge.first] = new_time;
                next_to_proccess.push({edge.first, distances[edge.first]});
            }
        }
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int V, E, start, end;
    std::cin >> V >> E >> start >> end;
    
    for(int v = 0; v < V; v++){
        std::cin >> intervals_of_time[v];
    }
    
    input_graph(E);
    
    std::cout << dijkstra(V, start, end);
    
    return 0;
}
