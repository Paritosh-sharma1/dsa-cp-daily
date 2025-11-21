Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int,int>> q;

        dist[0][0] = 1;
        q.push({0,0});

        int delrow[8] = {-1,-1,0,1,1,1,0,-1};
        int delcol[8] = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i=0; i<8; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol] == 0){
                    if(dist[r][c] + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = dist[r][c] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return (dist[n-1][n-1] == 1e9 ? -1 : dist[n-1][n-1]);
    }
};
