class Solution {
public:
    int solve(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(amount==0){
            return 0;
        }
        if (idx == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9; // impossible
        }
        if (dp[idx][amount] != -1) return dp[idx][amount];

        int notpick = solve(idx - 1, coins, amount, dp);
        int pick = 1e9;
        if (coins[idx] <= amount)
            pick = 1 + solve(idx, coins, amount - coins[idx], dp);

        return dp[idx][amount] = min(pick, notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
