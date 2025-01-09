#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct UnionFind{
public:
    UnionFind(int vertices) : parents(vertices), sizes(vertices){
        for(int i = 0; i < vertices; i++){
            sizes[i] = 1;
            parents[i] = i;
        }
    }
    
    bool inOneComponent(int first, int second){
        return getParent(first) == getParent(second);
    }
    
    void uniteComponents(int first, int second){
        int firstParent = getParent(first);
        int secondParent = getParent(second);
        
        if(firstParent == secondParent){
            return;
        }
        
        if(sizes[firstParent] < sizes[secondParent]){
            std::swap(firstParent, secondParent);
        }
        
        parents[secondParent] = firstParent;
        sizes[firstParent] += sizes[secondParent];
    }
private:
    int getParent(int child){
        if(parents[child] == child){
            return child;
        }
        
        return parents[child] = getParent(parents[child]);
    }
    
    std::vector<int> parents;
    std::vector<int> sizes;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int N, M;
    std::cin >> N >> M;
    
    UnionFind uf(N);
    
    for(int i = 0; i < M; i++){
        int t1, t2;
        std::cin >> t1 >> t2;
        
        uf.uniteComponents(t1 - 1, t2 - 1);
    }
    
    int Q;
    std::cin >> Q;
    std::vector<int> result;
    
    for(int i = 0; i < Q; i++){
        int query, t1, t2;
        
        std::cin >> query >> t1 >> t2;
        
        if(query == 1){
            int res = uf.inOneComponent(t1 - 1, t2 - 1)? 1 : 0;
            result.push_back(res);
        }
        else{            
            if(uf.inOneComponent(t1 - 1, t2 - 1)){
                continue;
            }
        
            uf.uniteComponents(t1 - 1, t2 - 1);
        }
    }
    
    for(const auto& res : result){
        std::cout << res;
    }
    
    return 0;
}
