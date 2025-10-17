class Solution {
  public:
    bool solve(int idx, vector<int>& arr, int sum, vector<vector<int>>& dp) {
    if (sum == 0) return true;
    if (idx == 0) return arr[0] == sum;

    if (dp[idx][sum] != -1) return dp[idx][sum]; //check

    bool pick = false;
    if (arr[idx] <= sum)
        pick = solve(idx - 1, arr, sum - arr[idx], dp);

    bool notpick = solve(idx - 1, arr, sum, dp);

    return dp[idx][sum] = pick || notpick;
}

bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return solve(n - 1, arr, sum, dp);
    }

};