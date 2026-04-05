Link:  https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/


using ll = long long;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        vector<ll> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<ll> ans;

        for (auto q : queries) {
            int idx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();

            ll count_left = idx;
            ll sum_left = prefix[idx];

            ll count_right = n - idx;
            ll sum_right = prefix[n] - prefix[idx];

            ll cost_left = (ll)q * count_left - sum_left;
            ll cost_right = sum_right - (ll)q * count_right;

            ans.push_back(cost_left + cost_right);
        }

        return ans;
    }
};