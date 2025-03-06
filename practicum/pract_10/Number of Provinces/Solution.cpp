class Solution {
public:
void dfs(int curr, vector<vector<int>>& isConnected, vector<bool>& visited) 
    {
        visited[curr] = true;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[curr][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        int number_of_provinces = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                number_of_provinces++;
                dfs(i, isConnected, visited);
            }
        }

        return number_of_provinces;
    }
};
