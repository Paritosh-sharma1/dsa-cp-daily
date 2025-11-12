Link: https://leetcode.com/problems/number-of-provinces/description/


class Solution {
public:
    void bfs(int i, vector<int>& vis, vector<vector<int>>& mat) {
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (int j = 0; j < mat.size(); j++) {
                if (mat[node][j] == 1 && !vis[j]) {
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
       int n = mat.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                bfs(i, vis, mat);
            }
        }
        return cnt;
    }
};