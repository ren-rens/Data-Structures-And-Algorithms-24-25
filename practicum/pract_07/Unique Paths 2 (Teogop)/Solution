class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        //fillin the first row of out dp until we meet an obstacle
        for(int i = 0; i < n; i++)
        {
            if(obstacleGrid[0][i] == 1)
                break;
            
            dp[0][i] = 1;
        }
        //filling the first coll of the dp until we meet an obsatcle with 1(only one path is possible)
        for(int j = 0; j < m; j++)
        {
            if(obstacleGrid[j][0] == 1)
                break;
            dp[j][0] = 1;
        }

        //filling the whole dp
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];//the result will be in the end cell
    }
};
