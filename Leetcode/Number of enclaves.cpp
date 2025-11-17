Link: https://leetcode.com/problems/number-of-enclaves/description/


class Solution {
public:

    //It works on recursion and bactracking.
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int delrow[],int delcol[],int m,int n){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,delrow,delcol,m,n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        //first row
        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                dfs(0,j,vis,grid,delrow,delcol,m,n);
            }
        }
        //last row
        for(int j=0;j<n;j++){
            if(grid[m-1][j]==1){
                dfs(m-1,j,vis,grid,delrow,delcol,m,n);
            }
        }
        //first col
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(i,0,vis,grid,delrow,delcol,m,n);
            }
        }
        //last col
        for(int i=0;i<m;i++){
            if(grid[i][n-1]==1){
                dfs(i,n-1,vis,grid,delrow,delcol,m,n);
            }
        }
        int cnt=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};