struct UnionFind{
public:
    UnionFind(int vertices): parents(vertices), sizes(vertices){
        for(int i = 0; i < vertices; i++){
            parents[i] = i;
            sizes[i] = 1;
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
