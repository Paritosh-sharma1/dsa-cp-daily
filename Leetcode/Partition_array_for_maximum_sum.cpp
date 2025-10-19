class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0); // dp[n] = 0 base case

        // Fill from right to left
        for (int i = n - 1; i >= 0; i--) {
            int currMax = 0;
            int best = 0;

            // Try all partition sizes up to k
            for (int j = i; j < n && j < i + k; j++) {
                currMax = max(currMax, arr[j]);  // max value in current block
                int len = j - i + 1;             // block length

                // Option: take this block and add the best from next part
                best = max(best, currMax * len + dp[j + 1]);
            }

            dp[i] = best;
        }

        return dp[0];
    }
};
