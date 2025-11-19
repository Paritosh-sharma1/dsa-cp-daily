Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
  


//DFS
class Solution {
  public:
  
  
  bool dfs(int node,vector<int>& vis,vector<int>&pathVis,vector<vector<int>>& adj){
      vis[node]=1;
      pathVis[node]=1;
      for(auto nbr:adj[node]){
          if(!vis[nbr]){
              if(dfs(nbr,vis,pathVis,adj)==true) return true;
          }
          else if(pathVis[nbr]){//Cycle detection
              return true;
          }
      }
      pathVis[node]=0;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            int u=e[0];
            int v= e[1];
            adj[u].push_back(v);
        }
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        //Connected components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true)return true;
                
            }
        }
        return false;
    }
};

//BFS Khan's algo simple bfs cannot detect cycle in a graph
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
            indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        if(cnt==V)return false;
        return true;
    }
};