#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        
        // Build adjacency list
        vector<vector<int>> adj(N);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        
        // BFS for shortest path
        vector<int> dist(N, 1e9);
        queue<int> q;
        
        dist[src] = 0;
        q.push(src);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        
        return dist;
    }
};

int main() {

    int N = 9, M = 10;
    vector<vector<int>> edges = {
        {0,1},{0,3},{3,4},{4,5},{5,6},
        {1,2},{2,6},{6,7},{7,8},{6,8}
    };

    Solution obj;
    vector<int> ans = obj.shortestPath(edges, N, M, 0);

    for (int d : ans) cout << d << " ";
}
