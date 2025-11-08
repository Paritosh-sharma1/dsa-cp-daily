Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                } else if (nums[i] > nums[j] && dp[i] == 1 + dp[j]) {
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            cout << cnt[i] << " ";
            if (dp[i] == maxi) {
                cnt1 += cnt[i];
            }
        }
        return cnt1;
    }
};