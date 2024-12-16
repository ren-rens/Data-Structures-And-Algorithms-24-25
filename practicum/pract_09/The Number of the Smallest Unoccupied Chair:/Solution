struct Friend
{
    int arrives, leaves, idx;

    bool operator<(const Friend& other)
    {
        return this->arrives < other.arrives;
    }
};
struct Guest
{
    int leaves, chair;
};

auto compareGuest = [](const Guest& lhs, const Guest& rhs)
{
    return lhs.leaves > rhs.leaves;
};

class Solution 
{
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        vector<Friend> friends;
        for(int i = 0; i < times.size(); i++)
        {
            friends.push_back({times[i][0], times[i][1], i});
        }
        std::sort(friends.begin(), friends.end());

        std::priority_queue<int, vector<int>, std::greater<int>> availableChairs;
        for(int i = 0; i < times.size(); i++)
            availableChairs.push(i);

        std::priority_queue<Guest, vector<Guest>, decltype(compareGuest)> guest(compareGuest);
        for(int i = 0; i < friends.size(); i++)
        {
            while(guest.size() && guest.top().leaves <= friends[i].arrives)
            {
                availableChairs.push(guest.top().chair);
                guest.pop();
            }

            if(friends[i].idx == targetFriend)
                return availableChairs.top();

            guest.push({friends[i].leaves, availableChairs.top()});
            availableChairs.pop();
        }

        return 1;
    }
};
