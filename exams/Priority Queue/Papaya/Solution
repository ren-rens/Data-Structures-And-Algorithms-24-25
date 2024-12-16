#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void input(std::priority_queue<int, vector<int>, std::greater<int>>& papaya, int N){
    for(int i = 0; i < N; i++){
        int cur;
        std::cin >> cur;
        
        papaya.push(cur);
    }
}

int dayCount(std::priority_queue<int, vector<int>, std::greater<int>>& papaya, int S){
    int count = 0;
    
    while(true){
        if(papaya.top() >= S){
            break;
        }
        
        if(papaya.size() < 2){
            return -1;
        }
        
        int s1 = papaya.top();
        papaya.pop();
        int s2 = papaya.top();
        papaya.pop();
        
        papaya.push(s1 + 2 * s2);
        count++;
    }
    
    return count;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, S;
    std::cin >> N >> S;
    
    std::priority_queue<int, vector<int>, std::greater<int>> papaya;
    input(papaya, N);
    
    int count = dayCount(papaya, S);
    
    std::cout << count;
    return 0;
}
