class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::pair<int,int>> numbers;
        int size = nums.size();

        vector<int> res(2, -1);

        for(int i = 0; i < size; i++)
        {
            if (numbers.find(nums[i]) == numbers.end()) {
                numbers[nums[i]] = {1, i};
            } 
            else {
                numbers[nums[i]].first++;
                numbers[nums[i]].second = i;
            }
        }

        for(int i = 0; i < size; i++)
        {
            auto iter = numbers.find(target - nums[i]);
            if(iter != nullptr)
            {
                if(iter->first == nums[i] && iter->second.first == 1)
                    continue;
                res[0] = i;
                res[1] = iter->second.second;
                break;
            }
        }

        return res;
    }
};
