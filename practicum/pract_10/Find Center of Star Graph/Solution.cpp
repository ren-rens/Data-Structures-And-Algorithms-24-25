class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        std::vector<int> degree(n + 1 ,0);

        for(auto& relation: edges)
        {
            degree[relation[0]]++;
            degree[relation[1]]++;
        }

        int max_count = 0;
        int max_degree = -1;
        for(int i = 1; i <= n; ++i)
        {
            if(max_count < degree[i])
            {
                max_degree = i;
                max_count = degree[i];
            }
        }
        return max_degree;
    }
};
