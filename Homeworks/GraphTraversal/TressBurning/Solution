#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct Node{
    bool isBurning; // a flag wether a tree is burning
    int inComponent; // the component index in which our tree is at
};

struct Rectangle{
    int up = 4002;
    int down = 0;
    int right = 0; 
    int left = 4002;
};


vector<Node> matrix[4000]; // the matrix we need to fill
vector<pair<int, int>> coordinates; // the coordinates of all trees that are burning
int N; // the size of our matrix

void input(){
    std::cin >> N;

    for(int i = 0; i < N; i++){
        matrix[i] = vector<Node>(N);
        for(int j = 0; j < N; j++){
            std::cin >> matrix[i][j].isBurning;
            
            if(matrix[i][j].isBurning == true){
                coordinates.push_back({i, j});// the coordinates of all burning trees in the matrix :)
            }
        }
    }
}

void dfs(vector<Rectangle>& areas, int inComponent, int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N){
        return;
    }
    
    if(matrix[x][y].inComponent || !matrix[x][y].isBurning){
        return;
    }
    
    matrix[x][y].inComponent = inComponent;
    if (areas[inComponent].up > x)
        areas[inComponent].up = x;
    if (areas[inComponent].down < x)
        areas[inComponent].down = x;
    if (areas[inComponent].left > y)
        areas[inComponent].left = y;
    if (areas[inComponent].right < y)
        areas[inComponent].right = y;
    
    dfs(areas, inComponent, x + 1, y);
    dfs(areas, inComponent, x - 1, y);
    dfs(areas, inComponent, x, y + 1);
    dfs(areas, inComponent, x, y - 1);
    
}

void fillAreas(vector<Rectangle>& areas, int& inComponent){
    for(auto& curCoord : coordinates){
        if(matrix[curCoord.first][curCoord.second].inComponent != 0){
            continue; // we already found this component and solved its area :)
        }
        
        areas.push_back(Rectangle());
        
        dfs(areas, inComponent, curCoord.first, curCoord.second);
        
        inComponent++;
    }
}

std::priority_queue<int> fillQueue(int inComponent, vector<Rectangle>& areas){
     std::priority_queue<int> result;
    
     for(int i = 1; i < inComponent; i++){
        result.push((areas[i].down - areas[i].up + 1) * (areas[i].right - areas[i].left + 1));
     }
    
    return result;
}

void printResult(std::priority_queue<int>& result){
    while(!result.empty()){
        std::cout << result.top() << ' ';
        result.pop();
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */      
    
    input();
    
    vector<Rectangle> areas(1);
    int inComponent = 1;
    fillAreas(areas, inComponent);
    
    std::priority_queue<int> result = fillQueue(inComponent, areas);
    
    printResult(result);
    
    return 0;
}
