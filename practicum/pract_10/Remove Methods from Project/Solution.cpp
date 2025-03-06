void dfs(const vector<vector<int>> &graph, vector<bool> &visited,
int current, unordered_set<int> &suspicious) {
    if (visited[current])
        return;

    suspicious.insert(current);
    visited[current] = true;

    for (int node : graph[current]) {
        dfs(graph, visited, node, suspicious);
    }
}

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {
        vector<vector<int>> graph(n);
        for (const auto &edge : invocations) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(n, false);
        unordered_set<int> suspicious;

        // Perform DFS starting from node `k`
        dfs(graph, visited, k, suspicious);

        // Nodes that are not suspicious
        unordered_set<int> allNodes;
        for (int i = 0; i < n; ++i)
            allNodes.insert(i);

        vector<int> non_suspicious;
        for (int i = 0; i < n; ++i) {
            if (suspicious.find(i) == suspicious.end()) {
                non_suspicious.push_back(i);
            }
        }

        // Check for invocations from non-suspicious nodes
        unordered_set<int> non_suspicious_invocations;
        for (int node : non_suspicious) {
            for (int neighbor : graph[node]) {
                non_suspicious_invocations.insert(neighbor);
            }
        }

        // Intersection check between suspicious and non-suspicious invocations
        for (int node : non_suspicious_invocations) {
            if (suspicious.find(node) != suspicious.end()) {
                // If any invocation leads to a suspicious node, return all nodes
                vector<int> allNodesVec(allNodes.begin(), allNodes.end());
                return allNodesVec;
            }
        }

        return non_suspicious;
    }
};
