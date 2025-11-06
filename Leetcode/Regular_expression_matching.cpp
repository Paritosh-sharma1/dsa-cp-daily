Link: https://leetcode.com/problems/regular-expression-matching/


class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;              
        if (j < 0 && i >= 0) return false;             
        if (i < 0 && j >= 0) {           
            for (int k = j; k >= 0; k -= 2) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        bool flag = false;
        if (p[j] == s[i] || p[j] == '.') {
            flag = solve(i - 1, j - 1, s, p, dp);
        }
        else if (p[j] == '*') {
            flag = solve(i, j - 2, s, p, dp);
            if (p[j - 1] == s[i] || p[j - 1] == '.') {
                flag = flag || solve(i - 1, j, s, p, dp);
            }
        }

        return dp[i][j] = flag;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s, p, dp);
    }
};
