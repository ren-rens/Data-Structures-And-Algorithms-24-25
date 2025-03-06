class Solution {
public:
    std::set<std::string> set;
    std::string res, current;
    void backtracking(int n)
    {
       if(!res.empty())
            return;
        
        if(n == 0) 
        {
            if (set.count(current) == 0)
                res = current;
            return;
        }

        current += '0';
        backtracking(n - 1);
        current.pop_back();

        current += '1';
        backtracking(n - 1);
        current.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto num : nums)
            set.insert(num);

        backtracking(nums.size());

        return res;        
    }
};
