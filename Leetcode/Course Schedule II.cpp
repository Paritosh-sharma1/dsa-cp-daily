Link: https://leetcode.com/problems/course-schedule-ii/


//Using Khan's algo (bfs)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            cout << indegree[i] << " ";
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        vector<int>ans;
        while (!q.empty()) {
            cnt++;
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (cnt == numCourses) {
            return ans;
        } else {
            return {};
        }
    }
};

//Using dfs
class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<vector<int>>& adj, stack<int>& st) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int nxt : adj[node]) {
            if (!vis[nxt]) {
                if (dfs(nxt, vis, pathVis, adj, st))
                    return true;             
            }
            else if (pathVis[nxt]) {
                return true;                 
            }
        }

        pathVis[node] = 0;
        st.push(node);                       
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Correct edge: b → a
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0), pathVis(numCourses, 0);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj, st))
                    return {};                 
            }
        }

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};
