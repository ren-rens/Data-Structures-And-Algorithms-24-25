class Solution {
public:
    void dfs(int currentRoom, vector<vector<int>>& rooms, vector<bool>& visited) 
    {
        visited[currentRoom] = true;  
        for (int key : rooms[currentRoom]) 
        {  
            if (!visited[key])   
                dfs(key, rooms, visited);  
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> visited(n, false);  
        dfs(0, rooms, visited);  

        for (bool roomVisited : visited) 
        {
            if (!roomVisited) 
                return false;
        }

        return true;
    }
};
