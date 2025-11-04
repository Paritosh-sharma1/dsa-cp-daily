Link: https://leetcode.com/problems/distinct-subsequences/description/

//Memoization
class Solution {
public:
    long long solve(int i, int j, string &s, string &t, vector<vector<long long>> &dp) {
        if (j < 0) return 1;       
        if (i < 0) return 0;       
        if (dp[i][j] != -1) return dp[i][j];
        long long take = 0, notTake = 0;
        if (s[i] == t[j]) {
            take = solve(i - 1, j - 1, s, t, dp);
        }

        notTake = solve(i - 1, j, s, t, dp);

        return dp[i][j] = take + notTake;
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return solve(n - 1, m - 1, s, t, dp);
    }
};

//Tabulation
class Solution {
public:

const int prime = 1e9 + 7;

    long long numDistinct(string s1, string s2) {
        int n=s1.size(),m=s2.size();
         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; i++) {
        dp[0][i] = 0;
    }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
   return dp[n][m];
    }
};
