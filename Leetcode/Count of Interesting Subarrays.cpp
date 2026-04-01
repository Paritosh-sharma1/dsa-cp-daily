Link: https://leetcode.com/problems/count-of-interesting-subarrays/description/


class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long ans = 0;

        vector<int> count(n + 1, 0);

for (int i = 1; i <= n; i++) {
    count[i] = count[i - 1];              
    if (nums[i - 1] % modulo == k) {
        count[i]++;                     
    }
}


        unordered_map<int, long long> mp;
        mp[0] = 1;  

        for (int i = 1; i <= n; i++) {
            int cur = count[i] % modulo;
            int need = (cur - k + modulo) % modulo;
            ans += mp[need];
            mp[cur]++;
        }

        return ans;
    }
};