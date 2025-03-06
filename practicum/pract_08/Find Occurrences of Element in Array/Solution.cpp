class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) 
    {
        //moje i s vector :)

        std::unordered_map<int, std::vector<int>> occurrences;

        for (int i = 0; i < nums.size(); ++i)
            occurrences[nums[i]].push_back(i);

        std::vector<int> result;

        for (int query : queries) 
        {
            if (occurrences.count(x) > 0 && query <= occurrences[x].size()) 
                result.push_back(occurrences[x][query - 1]); 
            else 
                result.push_back(-1); 
        }

        return result;
    }
};
