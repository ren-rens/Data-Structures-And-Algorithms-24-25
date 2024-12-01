class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        std::unordered_set<int> st;

        int result = 0, current_max = 0;
        int start = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            while(st.count(nums[i]))
            {
                st.erase(nums[start]);
                current_max -= nums[start];
                ++start;
            }

            st.insert(nums[i]);
            current_max += nums[i];
            result = std::max(result, current_max);
        }
        return result;

    }
};
