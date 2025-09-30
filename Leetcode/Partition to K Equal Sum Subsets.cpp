#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backtrack(vector<int>& nums, vector<bool>& used, int k, int start, int currSum, int target) {
        if (k == 1) return true; // last group auto works
        if (currSum == target) {
            // one subset done, build next
            return backtrack(nums, used, k-1, 0, 0, target);
        }

        for (int i = start; i < nums.size(); i++) {
            if (!used[i] && currSum + nums[i] <= target) {
                used[i] = true;
                if (backtrack(nums, used, k, i+1, currSum + nums[i], target))
                    return true;
                used[i] = false; // backtrack
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        int target = sum / k;
        sort(nums.rbegin(), nums.rend()); // helps pruning
        if (nums[0] > target) return false;

        vector<bool> used(n, false);
        return backtrack(nums, used, k, 0, 0, target);
    }
};
