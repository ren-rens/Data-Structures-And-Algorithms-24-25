#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> nums_and_idx(nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            nums_and_idx[i].first = nums[i];
            nums_and_idx[i].second = i;
        }

        sort(nums_and_idx.begin(), nums_and_idx.end());

        for (size_t i = 1; i < nums_and_idx.size(); i++)
        {
            if (nums_and_idx[i - 1].first == nums_and_idx[i].first
                && abs
                (nums_and_idx[i - 1].second - nums_and_idx[i].second)
                <= k)
                return true;
        }
        return false;
    }
};