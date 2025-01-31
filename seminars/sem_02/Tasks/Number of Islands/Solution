class Solution {
private:
    void markIsLand(vector<vector<char>>& grid, long long i , long long j, long long N, long long M){
        if(i < 0 || i >= N || j < 0 || j >= M){
            return;
        }

        if(grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '0';

        markIsLand(grid, i - 1, j, N, M);
        markIsLand(grid, i, j - 1, N, M);
        markIsLand(grid, i + 1, j, N, M);
        markIsLand(grid, i, j + 1, N, M);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        long long N = grid.size();
        long long M = grid[0].size();

        for(long long i = 0; i < N; i++){
            for(long long j = 0; j < M; j++){
                if(grid[i][j] == '1') {
                    markIsLand(grid, i, j, N, M);
                    result++;
                }
            }
        }

        return result;
    }
};
