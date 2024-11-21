class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int costs[1000]{};
        costs[0] = cost[0];
        costs[1] = cost[1];

        for(int i = 2; i < cost.size(); i++)
        {
            costs[i] = min(costs[i - 2], costs[i - 1]) + cost[i];
        }
        
        return min(costs[cost.size() - 1], costs[cost.size() - 2]);
    }
};
