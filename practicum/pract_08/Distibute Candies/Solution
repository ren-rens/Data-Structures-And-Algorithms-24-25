class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        std::unordered_map<int,int> different_candies;

        for(int i : candyType)
        {
            different_candies[i]++;
        }

        return std::min(different_candies.size(), candyType.size() / 2);
    }
};
