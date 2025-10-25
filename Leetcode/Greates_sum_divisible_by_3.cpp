Link:https://leetcode.com/problems/greatest-sum-divisible-by-three/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    int solve(int i, int rem, vector<int> &nums, vector<vector<int>> &dp) {
        if(i == nums.size()) {
            return (rem == 0 ? 0 : INT_MIN);
        }
        if(dp[i][rem] != -1)
            return dp[i][rem];
        int pick = nums[i] + solve(i + 1, (rem + nums[i]) % 3, nums, dp);

        int notpick = solve(i + 1, rem, nums, dp);

        return dp[i][rem] = max(pick, notpick);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int ans = solve(0, 0, nums, dp);
        return max(ans, 0); 
    }
};
