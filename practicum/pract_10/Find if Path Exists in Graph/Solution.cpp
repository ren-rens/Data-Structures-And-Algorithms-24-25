class Solution {
public:
    bool dfs(int current, int destination, unordered_set<int> &visited, unordered_map<int, unordered_set<int>> &graph) 
    {
        if (current == destination)  
            return true;

        visited.insert(current);

        for (auto& neighbor : graph[current]) 
        {
            if (!visited.count(neighbor)) 
            {
                if (dfs(neighbor, destination, visited, graph))  
                    return true;
            }
        }

        return false;  
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        if (source == destination)  
            return true;

        unordered_map<int, unordered_set<int>> graph;

        for (auto& relation : edges) 
        {
            graph[relation[0]].insert(relation[1]);
            graph[relation[1]].insert(relation[0]);
        }

        unordered_set<int> visited;

        return dfs(source, destination, visited, graph);  // Start DFS from the source
    }
};
