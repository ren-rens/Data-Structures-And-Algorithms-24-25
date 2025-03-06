class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //OSNOWNA ZADACHA!!!!!!
        int size = nums.size();

        int lis[2500]{};
        lis[0] = 1;
        
        for(int i = 1; i < size; i++)
        {
            int max = 0;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                    max = std::max(lis[j], max);
            }
            lis[i] = 1 + max;
        }

        return *std::max_element(lis, lis + size);
    }
};
