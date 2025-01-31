class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size() - 1;
        int cur_mid = nums[0];
        while(l <= r)
        {
            if(nums[l] < nums[r])
            {
                //we are in a sorted array
                cur_mid = min(nums[l], cur_mid);
                break;
            }

            int mid = l + (r - l) / 2;
            cur_mid = min(cur_mid, nums[mid]);

            if(nums[mid] < nums[l])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return cur_mid;
    }
};
