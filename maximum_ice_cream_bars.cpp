#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        if (costs.size() < 1 ||
            costs.size() > pow(10, 5) ||
            coins < 1 || coins > pow(10, 8))
            return -1;

        sort(costs.begin(), costs.end());

        int max_bars = 0;
        for (size_t i = 0; i < costs.size(); i++)
        {
            if (coins >= costs[i])
            {
                max_bars++;
                coins -= costs[i];
            }

        }
        return max_bars;
    }
};