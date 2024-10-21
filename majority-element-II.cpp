#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        size_t min_occ = nums.size() / 3;
        vector<int> result;

        std::sort(nums.begin(), nums.end());

        int size = nums.size();
        int target = size / 3;

        for (size_t i = 0; i < size - target; i++)
        {
            if (nums[i] == nums[i + target])
            {
                if (result.empty() ||
                    result.back() != nums[i])
                    result.push_back(nums[i]);

                i += target;
            }
        }

        return result;
    }
};