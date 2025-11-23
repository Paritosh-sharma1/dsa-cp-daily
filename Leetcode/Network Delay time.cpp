Link: https://leetcode.com/problems/network-delay-time/description/



class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [currdist, node] = pq.top();
            pq.pop();

            for(auto &it : adj[node]){
                int adjnode = it.first;
                int edw = it.second;

                if(currdist + edw < dist[adjnode]){
                    dist[adjnode] = currdist + edw;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        int maxi = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};
