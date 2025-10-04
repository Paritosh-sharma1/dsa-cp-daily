#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<int> nums;
    vector<double> prefix;
    vector<vector<double>> dp;

    // Helper: average of subarray [i..j]
    double getAvg(int i, int j) {
        return (prefix[j+1] - prefix[i]) / (j - i + 1);
    }

    double solve(int i, int k) {
        if (i == n) return 0.0;              // no elements left
        if (k == 1) return getAvg(i, n-1);   // last group = average of rest
        if (dp[i][k] >= 0) return dp[i][k];  // already computed

        double ans = 0.0;
        // try partition between i..j and rest
        for (int j = i; j < n; j++) {
            if (n - (j+1) >= k-1) { // ensure enough elements left
                ans = max(ans, getAvg(i, j) + solve(j+1, k-1));
            }
        }
        return dp[i][k] = ans;
    }

    double largestSumOfAverages(vector<int>& arr, int K) {
        nums = arr;
        n = nums.size();

        prefix.assign(n+1, 0);
        for (int i = 0; i < n; i++) 
            prefix[i+1] = prefix[i] + nums[i];

        dp.assign(n+1, vector<double>(K+1, -1.0));
        return solve(0, K);
    }
};