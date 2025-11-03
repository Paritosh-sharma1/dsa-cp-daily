Link: https://leetcode.com/problems/delete-operation-for-two-strings/


class Solution {
public:
    int solve(int i,int j,string& s,string& t,vector<vector<int>>& dp,int n,int m){
        if(i==n || j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int first=0,sec=0;
        if(s[i]==t[j]){
            first =1+solve(i+1,j+1,s,t,dp,n,m);
        }
        else{
            sec=max(solve(i,j+1,s,t,dp,n,m),solve(i+1,j,s,t,dp,n,m));
        }
        return dp[i][j]=max(first,sec);
    }
    int minDistance(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int len = solve(0,0,s,t,dp,n,m);
        return n+m-2*len;
    }
};