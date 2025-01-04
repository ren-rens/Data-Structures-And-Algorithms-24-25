#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

struct Node{
    int distance, x, y;
    
    bool operator<(const Node& other) const{
        return distance > other.distance;
    }
};

const int MAX_SIZE = 1000;
int N, M;
int dist[MAX_SIZE][MAX_SIZE];
std::priority_queue<Node> proccess;

void input_graph(std::vector<std::vector<int>>& graph){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char current;
            std::cin >> current;
            graph[i][j] = (current == '.' ? 0 : 1);
            dist[i][j] = INT_MAX;
        }
    }
}

void input_boundaries(const std::vector<std::vector<int>>& graph){
    //first and last rows
    for(int i = 0; i < M; i++){
        dist[0][i] = graph[0][i];
        dist[N - 1][i] = graph[N - 1][i];
        
        proccess.push({graph[0][i], 0, i});
        proccess.push({graph[N - 1][i], N - 1, i});
    }
    
    //first and last colls (we start from the 1 index because we have filled it in the past for)
    for(int i = 1; i < N - 1; i++){
        dist[i][0] = graph[i][0];
        dist[i][M - 1] = graph[i][M - 1];
        
        proccess.push({graph[i][0], i, 0});
        proccess.push({graph[i][M - 1], i, M - 1});
    }
}

bool can_be_moved(int x, int y){
    //if we have reached the boundaries - it is the end of the mansion
    return x >= 0 && x <= N - 1 && y >= 0 && y <= M - 1;
}

void dijkstra(const std::vector<std::vector<int>>& graph){
    while(!proccess.empty()){
        auto current = proccess.top();
        proccess.pop();
        
        int new_dist = INT_MAX;
        if(can_be_moved(current.x - 1, current.y)){
            new_dist = current.distance + graph[current.x - 1][current.y];
            
            if(dist[current.x - 1][current.y] > new_dist){
                dist[current.x - 1][current.y] = new_dist;
                proccess.push({new_dist, current.x - 1, current.y});
            }
        }
        if(can_be_moved(current.x + 1, current.y)){
            new_dist = current.distance + graph[current.x + 1][current.y];
            
            if(dist[current.x + 1][current.y] > new_dist){
                dist[current.x + 1][current.y] = new_dist;
                proccess.push({new_dist, current.x + 1, current.y});
            }
        }
        if(can_be_moved(current.x, current.y - 1)){
            new_dist = current.distance + graph[current.x][current.y - 1];
            
            if(dist[current.x][current.y - 1] > new_dist){
                dist[current.x][current.y - 1] = new_dist;
                proccess.push({new_dist, current.x, current.y - 1});
            }
        }
        if(can_be_moved(current.x, current.y + 1)){
            new_dist = current.distance + graph[current.x][current.y + 1];
            if(dist[current.x][current.y + 1] > new_dist){
                dist[current.x][current.y + 1] = new_dist;
                proccess.push({new_dist, current.x, current.y + 1});
            }
        }
    }
}

int find_result(const vector<vector<int>>& graph) {
    int maxDist = -1, count = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == 0) {
                if(dist[i][j] > maxDist) {
                    maxDist = dist[i][j];
                    count = 1;
                } else if(dist[i][j] == maxDist) {
                    count++;
                }
            }
        }
    }
    return count;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> graph(N, std::vector<int>(M,0));
    input_graph(graph);
    
    input_boundaries(graph);
    
    dijkstra(graph);
    
    std::cout << find_result(graph);
    
}
