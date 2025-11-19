Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


// using bfs
class Solution {
  public:

    bool bfs(int start, vector<int>& vis, vector<vector<int>>& adj) {
        queue<pair<int,int>> q;  // {node, parent}
        vis[start] = 1;
        q.push({start, -1});

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(int nbr : adj[node]) {
                if(!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push({nbr, node});
                } 
                else if(nbr != parent) {
                    // revisiting a visited node that is not parent -> cycle
                    return true;
                }
            }
        }
        return false;
    }


    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);   // build adjacency list

        // Build in O(E)
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);

        // Check all components
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(bfs(i, vis, adj)) return true;
            }
        }

        return false;
    }
};

//using dfs
class Solution {
  public:
  
  
    bool dfs(int node,int parent,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto nbr:adj[node]){
            if(!vis[nbr]){
                if(dfs(nbr,node,vis,adj)==true) return true;
            }
            else if(parent!=nbr){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        //Adj list
        for(auto &e:edges){
            int u= e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);
        //Connected Components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)) return true;
            }
        }
        return false;
    }
};