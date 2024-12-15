class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDeg(n);

        for(auto& element : edges){
            inDeg[element[1]]++;
        }

        int result = -1;
        for(int i = 0; i < n; i++){
            if(result == -1 && inDeg[i] == 0){
                result = i;
            }
            else if(result != -1  && inDeg[i] == 0){
                return -1;
            }
        }

        return result;
    }
};
