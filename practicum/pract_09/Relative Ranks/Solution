#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::string getPosition(int position) 
    {
        if (position == 1)
            return "Gold Medal";
        if (position == 2)
            return "Silver Medal";
        if (position == 3)
            return "Bronze Medal";
        else
            return std::to_string(position);
    }

    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::priority_queue<int> pq(score.begin(), score.end());
        
        std::unordered_map<int, int> scoreToRank;
        int rank = 1;
        while (!pq.empty()) 
        {
            int topScore = pq.top();
            pq.pop();
            scoreToRank[topScore] = rank++; 
        }

        std::vector<std::string> result(score.size());
        for (size_t i = 0; i < score.size(); ++i) 
        {
            result[i] = getPosition(scoreToRank[score[i]]);
        }

        return result;
    }
};
