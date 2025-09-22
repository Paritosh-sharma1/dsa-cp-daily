#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < n - 1 && nums[l] <= nums[l + 1]) l++;
        if (l == n - 1) return 0;

        while (r > 0 && nums[r] >= nums[r - 1]) r--;

        int sub_min = INT_MAX, sub_max = INT_MIN;
        for (int i = l; i <= r; i++) {
            sub_min = min(sub_min, nums[i]);
            sub_max = max(sub_max, nums[i]);
        }

        while (l > 0 && nums[l - 1] > sub_min) l--;
        while (r < n - 1 && nums[r + 1] < sub_max) r++;

        return r - l + 1;
    }
};