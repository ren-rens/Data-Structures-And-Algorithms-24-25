class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2,
    int n) {
        if(nums1.size() != m + n || nums2.size() != n || 
        m < 0 || m > 200 || n < 0 || n > 200 ||
        m + n < 1 || m + n > 200)
            return;

        vector<int> res (m + n);
        int firstIt = 0, secondIt = 0, resIt = 0;
        while(firstIt < m && secondIt < n)
            res[resIt++] = (nums1[firstIt] < nums2[secondIt] ?
            nums1[firstIt++] : nums2[secondIt++]);

        while(firstIt < m)
            res[resIt++] = nums1[firstIt++];

         while(secondIt < n)
            res[resIt++] = nums2[secondIt++];

        for(size_t i = 0; i < nums1.size(); i++)
            nums1[i] = res[i];

    }
};
