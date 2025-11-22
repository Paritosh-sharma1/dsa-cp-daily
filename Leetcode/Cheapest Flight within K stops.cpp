Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);   
        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // queue: {cost, node, stops}
        queue<array<int,3>> q;               
        q.push({0, src, 0});
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        while (!q.empty()) {
            auto [cost, node, stops] = q.front();
            q.pop();

            if (stops > k) continue;            
            
            for (auto &it : adj[node]) {
                int nxt = it.first;
                int wt  = it.second;

                if (cost + wt < dist[nxt]) {
                    dist[nxt] = cost + wt;
                    q.push({dist[nxt], nxt, stops + 1});
                }
            }
        }
        
        return dist[dst] == 1e9 ? -1 : dist[dst];   
    }
};