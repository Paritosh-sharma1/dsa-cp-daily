Link: https://leetcode.com/problems/find-eventual-safe-states/description/


//DFS
class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<int>& cycle,
             vector<int>& pathVis, vector<vector<int>>& adj) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {

            if (!vis[it]) {
                if (dfs(it, vis, cycle, pathVis, adj))
                    return true;
            }
            else if (pathVis[it] == 1) {
                return true;   
            }
        }

        pathVis[node] = 0;
        cycle[node] = 1; 
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {

        int n = adj.size();
        vector<int> vis(n, 0), pathVis(n, 0), cycle(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, vis, cycle, pathVis, adj);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (cycle[i] == 1)
                ans.push_back(i);
        }

        return ans;
    }
};