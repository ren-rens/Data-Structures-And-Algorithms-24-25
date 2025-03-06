class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> result(2, -1);

        auto lower = std::lower_bound(nums.begin(), nums.end(), target);

        if (lower == nums.end() || *lower != target)
        {
            return result;
        }

        auto upper = std::upper_bound(nums.begin(), nums.end(), target);

        result[0] = (lower - nums.begin());
        result[1] = (upper - nums.begin() - 1);

        return result;
    }
};
