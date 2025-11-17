Link: https://leetcode.com/problems/is-graph-bipartite/


// using dfs
class Solution {
public:


    bool dfs(int node,int col,vector<int>& color,vector<vector<int>>& graph){
        color[node]=col;
        for(auto it:graph[node]){
            if(color[it]==-1){
               if(dfs(it,!col,color,graph)==false){
                return false;
               }
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};


// using bfs

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<pair<int, int>> q; // {node,col}
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                q.push({i, 0});

                while (!q.empty()) {
                    int node = q.front().first;
                    int col = q.front().second;
                    q.pop();

                    for (auto it : graph[node]) {
                        if (color[it] == -1) {
                            color[it] = !col;
                            q.push({it, !col}); 
                        } else if (color[it] == col) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};