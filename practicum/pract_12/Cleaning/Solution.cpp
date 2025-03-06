#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct UnionFind{
public:
    UnionFind(int vertices): parents(vertices), sizes(vertices, 1){
        for(int i = 0; i < vertices; i++){
            parents[i] = i;
        }
    }
    
    void uniteComponents(int first, int second){
        int parentFirst = getParent(first);
        int parentsSecond = getParent(second);
        
        if(parentFirst == parentsSecond){
            return;
        }
        
        if(sizes[parentFirst] < sizes[parentsSecond]){
            std::swap(parentFirst, parentsSecond);
        }
        
        parents[parentsSecond] = parentFirst;
        sizes[parentFirst] += sizes[parentsSecond];
    }
    
    bool inOneComponent(int first, int second){
        return getParent(first) == getParent(second);
    }
private:
    std::vector<int> parents;
    std::vector<int> sizes;
    
    int getParent(int child){
        if(child == parents[child]){
            return child;
        }
        
        return parents[child] = getParent(parents[child]);
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M;
    std::cin >> N >> M;
    
    if(N == 1 && M == 0 || M == 1){
        std::cout << 0;
        return 0;
    }
    
    int final_time = -1;
    UnionFind uf(N + 1);
    int components = N;
    
    for(int i = 0; i < M; i++){
        int from, to;
        std::cin >> from >> to;
        
        if(uf.inOneComponent(from - 1, to - 1)){
            continue;
        }
        
        uf.uniteComponents(from - 1, to - 1);
        components--;
        
        if(components == 1){
            final_time = i + 1;
        }
    }
    
    std::cout << final_time;
    
    return 0;
}
