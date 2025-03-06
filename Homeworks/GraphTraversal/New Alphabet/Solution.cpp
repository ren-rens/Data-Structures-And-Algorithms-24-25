#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

vector<char> graph['z' + 1];
bool letters['z' + 1]{false};

stack<char> sorted;

bool visited['z' + 1];

size_t N;

void dfs(char letter)
{
    if(visited[letter]){
        return;
    }

    visited[letter] = true;

    for(auto& neighbour : graph[letter]){
        dfs(neighbour);
    }

    sorted.push(letter);
}

void inputWords(vector<std::string>& words){
    for(size_t i = 0; i < N; i++){
        std::cin >> words[i];
    }
}

void fillGraph(vector<string>& words){
    for(size_t i = 0; i < N - 1; i++){
        size_t len = std::min(words[i].length(), words[i + 1].length());
        
        for(size_t j = 0; j < len; j++){
            if(words[i][j] == words[i + 1][j]){
                continue;
            }
            
            graph[words[i][j]].push_back(words[i + 1][j]);
            
            letters[words[i][j]] = true;
            letters[words[i + 1][j]] = true;
            
            break;
        }
    }
}

void travelGraph(){
    for(char i = 'a'; i <= 'z'; i++){
        if(letters[i]){
            dfs(i);
        }
    }
}

void print(){
    while(!sorted.empty()){
        std::cout << sorted.top() << ' ';
        sorted.pop();
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    cin >> N;
    
    vector<string> words(N);
    inputWords(words);
    
    fillGraph(words);
    
    travelGraph();
    
    print();
    
    return 0;
}
