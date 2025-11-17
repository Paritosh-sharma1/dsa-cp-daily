Link: https://www.naukri.com/code360/problems/distinct-islands_630460?leftPanelTabValue=PROBLEM


#include<bits/stdc++.h>
vector<pair<int,int>> V; 

void dfs(int row,int col,int** arr,
         vector<vector<int>>& vis,
         int delrow[],int delcol[],
         int brow,int bcol,int n,int m)
{
    vis[row][col] = 1;

    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
           !vis[nrow][ncol] && arr[nrow][ncol] == 1)
        {
            // store relative position
            V.push_back({nrow - brow, ncol - bcol});

            // correct dfs call
            dfs(nrow, ncol, arr, vis, delrow, delcol, brow, bcol, n, m);
        }
    }
}



int distinctIslands(int** arr, int n, int m)
{
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int,int>>> st;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1 && !vis[i][j]){
                
                V.clear(); // reset container for new island
                V.push_back({0,0}); // include starting cell relative position

                dfs(i, j, arr, vis, delrow, delcol, i, j, n, m);

                st.insert(V); // store island shape
            }
        }
    }

    return st.size();
}
