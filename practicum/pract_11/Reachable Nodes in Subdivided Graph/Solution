struct Edge{
    int to, weight;
};

struct Node{
    int index, distance;

    bool operator<(const Node& other) const{
        return distance > other.distance;
    }
};

class Solution {
private:
    std::unordered_map<int, std::vector<Edge>> graph;
public:
    void dijkstra(std::vector<std::vector<int>>& done, std::vector<int>& dist, int max_moves, int& original_reached_nodes){
        dist[0] = 0;

        std::priority_queue<Node> pq;
        pq.push({0, 0});

        while(!pq.empty()){
            auto current = pq.top();
            pq.pop();

            if(current.distance > dist[current.index]){
                continue;
            }

            original_reached_nodes++;//the count of reached nodes in the original graph

            for(const auto& edge : graph[current.index]){
                int remaining_new_nodes = max_moves - current.distance;// Calculate how many subdivided nodes can be traversed on this edge
                if(remaining_new_nodes <= 0){
                    continue;//all of them are reachable
                }

                int used = std::min(remaining_new_nodes, edge.weight);
                done[current.index][edge.to] = std::max(done[current.index][edge.to], used);

                int new_dist = edge.weight + current.distance + 1;
                if(new_dist < dist[edge.to] && new_dist <= max_moves){
                    dist[edge.to] = new_dist;
                    pq.push({edge.to, new_dist});
                }
            }
        }
    }
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        for(int i = 0; i < n; i++){
            graph[i];
        }

        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        std::vector<int> dist(n, INT_MAX);
        std::vector<std::vector<int>> done(n, std::vector<int>(n, 0));
        int original_reached_nodes = 0;

        dijkstra(done, dist, maxMoves, original_reached_nodes);

        for(const auto& edge : edges){
            original_reached_nodes += min(edge[2], done[edge[0]][edge[1]] + done[edge[1]][edge[0]]);
        }

        return original_reached_nodes;
    }
};
