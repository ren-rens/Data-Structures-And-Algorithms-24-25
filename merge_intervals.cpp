#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort
        (intervals.begin(), intervals.end(),
            [](const vector<int>& lhs, const vector<int>& rhs)
            {
                return lhs[0] < rhs[0];
            }
        );

        vector<vector<int>> merged;
        vector<int> current = intervals[0];

        for (size_t i = 0; i < intervals.size(); i++)
        {
            if (current[1] >= intervals[i][0])
            {
                current[1] = max(current[1], intervals[i][1]);
            }
            else
            {
                merged.push_back(current);
                current = intervals[i];
            }
        }
        merged.push_back(current);
        return merged;
    }
};