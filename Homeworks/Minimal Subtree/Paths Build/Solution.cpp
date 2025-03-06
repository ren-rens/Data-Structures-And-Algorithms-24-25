#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Edge {
    size_t from, to, index;
    size_t cost;
    long long profit;
    
    bool operator<(const Edge& rhs) const {
        if(cost == rhs.cost) {
            return profit > rhs.profit;
        }
        
        return cost < rhs.cost;
    }
};

class UnionFind {
private:
    std::vector<size_t> parentsContainer, sizes;
    
public:
    UnionFind(size_t vertices): parentsContainer(vertices), sizes(vertices, 1) {
        for(size_t i = 0; i < vertices; i++){
            parentsContainer[i] = i;
        }
    }
    
    bool areInOneSet(size_t first, size_t second) {
        return getParent(first) == getParent(second);
    }
    
    size_t getParent(size_t vertex) {
        if(parentsContainer[vertex] == vertex) {
            return vertex;
        }
        
        return parentsContainer[vertex] = getParent(parentsContainer[vertex]);
    }
    
    void unionVertices(size_t first, size_t second) {
        size_t parentOfFirst = getParent(first);
        size_t parentOfSecond = getParent(second);
        
        if(parentOfFirst == parentOfSecond){
            return;
        }
        if(sizes[parentOfFirst] < sizes[parentOfSecond]){
            std::swap(parentOfFirst, parentOfSecond);
        }
        
        parentsContainer[parentOfSecond] = parentOfFirst;
        sizes[parentOfFirst] += sizes[parentOfSecond];
    }
};

void kruskal(std::vector<Edge>& edges, size_t verticesCount){
    std::sort(edges.begin(), edges.end());
    UnionFind graph(verticesCount);
    size_t unitedVertices = 0;
    
    for(auto& edge: edges) {
        if(graph.getParent(edge.from) != graph.getParent(edge.to)) {
            std::cout << edge.index << '\n';
            graph.unionVertices(edge.from, edge.to);
            unitedVertices++;
            if(unitedVertices + 1 == verticesCount) {
                break;
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;

    std::vector<Edge> edges(edgesCount);
    for(size_t i = 0; i < edgesCount; i++) {
        std::cin >> edges[i].from >> edges[i].to >> edges[i].cost >> edges[i].profit;
        --edges[i].from;
        --edges[i].to;
        edges[i].index = i + 1;
    }
    
    kruskal(edges, verticesCount);
    
    return 0;
}
