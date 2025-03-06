class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<1 || nums.size() > pow(10,5))
            return false;

        std::sort(nums.begin(), nums.end());

        for(size_t i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] < -pow(10,9) || nums[i] > pow(10,9))
                return false;

            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};
