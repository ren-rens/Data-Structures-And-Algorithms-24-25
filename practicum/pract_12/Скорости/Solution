#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <climits>
using namespace std;

struct Edge{
    int from, to, speed;
    
    bool operator<(const Edge& other) const{
        return speed < other.speed;
    }
};

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

Edge edges[(int)1e5];
int N, M, maxSpeed = INT_MAX, minSpeed = 0;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int t1, t2, speed;
        std::cin >> t1 >> t2 >> speed;
        
        edges[i] = {t1, t2, speed};
    }
    
    std::sort(edges, edges + M);
    
    for(int i = 0; i <  M - N + 1; i++){
        UnionFind uf(N + 1);
        
        int curMax = INT_MIN;
        int count = 0;
        
        for(int j = i; j < M; j++){
            if(uf.inOneComponent(edges[j].from - 1, edges[j].to - 1)){
                continue;
            }
            
            uf.uniteComponents(edges[j].from - 1, edges[j].to - 1);
            curMax = std::max(edges[j].speed, curMax);
            count++;
            
            if(count == N - 1){
                break;
            }
        }
        
        if(count == N - 1 && curMax - edges[i].speed < maxSpeed - minSpeed){
            minSpeed = edges[i].speed;
            maxSpeed = curMax;
        }
    }
    
    std::cout << minSpeed << ' ' << maxSpeed;

    return 0;
}
