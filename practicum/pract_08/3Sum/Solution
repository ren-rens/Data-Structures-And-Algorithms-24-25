class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());

        std:unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;

        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i + 1; j < nums.size() - 1; ++j)
            {
                int target = -(nums[i] + nums[j]);
                if(mp.count(target) && mp[target] > j)
                    res.push_back({nums[i], nums[j], target});
                j = mp[nums[j]];
            }
            i = mp[nums[i]];
        }
        return res;
    }
};
