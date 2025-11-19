Link: https://leetcode.com/problems/course-schedule/


//Using Khan's Algo (bfs)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
       
    for (auto &p : prerequisites) {
        int a = p[0];  
        int b = p[1]; 
        adj[b].push_back(a);
    }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            cout<<indegree[i]<<" ";
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==numCourses){
            return true;
        }
        else{
            return false;
        }
    }
};



//Using dfs cycle detection
class Solution {
public:


    bool dfs(int node,vector<int>& vis,vector<int>&pathVis,vector<vector<int>>& adj){
        vis[node]=1;
        pathVis[node]=1;
        for(auto nbr:adj[node]){
            if(!vis[nbr]){
                if(dfs(nbr,vis,pathVis,adj)==true){
                    return true;
                }
            }
            else if(pathVis[nbr]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            int a = it[0];
            int b= it[1];
            adj[b].push_back(a);
        }
        //connected components
        vector<int> vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true){
                    return false;
                }
            }
        }
        return true;
    }
};