class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() < n - 1)
            return -1;


        std::vector<int> inDeg(n + 1, 0);
        std::vector<int> outDeg(n + 1, 0);
        for(auto& el : trust)
        {
            inDeg[el[1]]++;
            outDeg[el[0]]++;
        }

        for(int i = 1; i <= n; ++i)
        {
            if(inDeg[i] == n - 1 && outDeg[i] == 0)
                return i;
        }
        return -1;
    }
};
