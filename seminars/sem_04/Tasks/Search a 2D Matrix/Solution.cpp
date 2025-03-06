class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size();
        int M = matrix[0].size();
        int i = 0;

        while(i < N && matrix[i][M - 1] < target){
            i++;
        }

        if(i == N){
            return false;
        }

        for(int j = 0; j < M; j++){
            if(matrix[i][j] == target){
                return true;
            }
        }

        return false;
    }
};
