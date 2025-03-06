#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

std::unordered_map<int, unordered_set<int>> graph;
std::unordered_set<int> friends;


int bfs(int start){
    
    std::queue<int> q;
    q.push(start);
    
    std::unordered_set<int> visited;
    visited.insert(start);
    
    
    int distance = 0;
    
    while(!q.empty()){
        int size = q.size();
        distance++;
        
        for(int i = 0; i < size; i++){
            int current = q.front();
            q.pop();
            
            if(friends.count(current) != 0 && current != start){
                return distance;
            }
            
            for(int neighbour : graph[current]){
                if(!visited.count(neighbour)){
                    q.push(neighbour);
                }
                
                visited.insert(current);
            }
        }
    }
    return 0;
}

int shortest_path(){
    int minDist = -1;
    
    for(auto& el : friends){
        int dist =  bfs(el);
        
        if(dist != 0){
            if(minDist != -1) 
                minDist = std::min(minDist, dist);
            else
                minDist = dist;
        }
    }
    
    return minDist != 1? minDist - 1 : -1;
}

void inputGraph(int M){
    for(int i = 0; i < M; i++){
        int x, y;
        std::cin >> x >> y;
        
        graph[x].insert(y);
        graph[y].insert(x);
    }
}

void inputGroups(int N){
    std::vector<int> groups(N);
    for(int i = 1; i <= N; i++){
        int group_number = 0;
        std::cin >> group_number;
        
        groups[i] = group_number;
    }
    
    int myGroup = 0;
    std::cin >> myGroup;
    
    for(int i = 1; i <= N; i++){
        if(groups[i] == myGroup){
            friends.insert(i);
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    
    inputGraph(M);
    
    inputGroups(N);
    
    std::cout << shortest_path();
    
    return 0;
}
