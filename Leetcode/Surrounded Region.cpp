Link: https://leetcode.com/problems/surrounded-regions/description/
   

//Using DFS 
class Solution {
public:

    void dfs(int row,int col,int m,int n,vector<vector<char>>& board,vector<vector<int>>& vis,int delrow[],int delcol[]){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,m,n,board,vis,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        int m=board.size(),n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
          for(int j=0; j<n; j++){
            if(board[0][j]=='O' && !vis[0][j])
                dfs(0, j, m, n, board, vis, delrow, delcol);

            if(board[m-1][j]=='O' && !vis[m-1][j])
                dfs(m-1, j, m, n, board, vis, delrow, delcol);
        }
        for(int i=0; i<m; i++){
            if(board[i][0]=='O' && !vis[i][0])
                dfs(i, 0, m, n, board, vis, delrow, delcol);

            if(board[i][n-1]=='O' && !vis[i][n-1])
                dfs(i, n-1, m, n, board, vis, delrow, delcol);
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<vis[i][j]<<" ";
        //         }
        //         cout<<endl;
        //     }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};



//Using BFS
class Solution {
public:
 void bfs(int row, int col, queue<pair<int, int>>& q,
             vector<vector<int>>& vis, vector<vector<char>>& board,
             int delrow[], int delcol[]) {
        int m = board.size(), n = board[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            vis[row][col] = 1;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                    !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                q.push({0, j});
                bfs(0, j, q, vis, board, delrow, delcol);
            }
            if (board[m - 1][j] == 'O' && !vis[m - 1][j]) {
                q.push({m - 1, j});
                bfs(m - 1, j, q, vis, board, delrow, delcol);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                q.push({i, 0});
                bfs(i, 0, q, vis, board, delrow, delcol);
            }
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
                q.push({i, n - 1});
                bfs(i, n - 1, q, vis, board, delrow, delcol);
            }
        }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};