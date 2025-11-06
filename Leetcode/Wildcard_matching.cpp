Link: https://leetcode.com/problems/wildcard-matching/

//Memoization
class Solution {
public:

    bool solve(int i,int j,string& s,string& p,vector<vector<int>>& dp){
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int e=j;e>=0;e--){
                if(p[e]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool flag =false;
        if(s[i]==p[j] || p[j]=='?'){
            flag = solve(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            flag = solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
        }
        return dp[i][j]=flag;
    }
    bool isMatch(string s, string p) {
        int n = s.size(),m=p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n-1,m-1,s,p,dp);
    }
};


//Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
        dp[0][0] = 1;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};