Link: https://leetcode.com/problems/longest-common-subsequence/description/

//Memoization
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
    int longestCommonSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0,0,s,t,dp,n,m);
    }
};

//Tabulation
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
};
