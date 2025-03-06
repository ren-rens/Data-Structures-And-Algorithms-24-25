class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(size_t iter = 0, nextIdx = 0; iter != nums.size(); iter++){
            if(nums[iter] != 0){
                std::swap(nums[iter], nums[nextIdx++]);
            }
        }
    }
};
