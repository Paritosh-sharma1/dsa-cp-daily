Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        map<int, int> mp;
        mp[0] = 1;  

        int sum = 0;
        int cnt = 0;

        for(int j = 0; j < n; j++) {
            sum += nums[j];

            int rem = sum % k;

            if(rem < 0) rem += k;

            cnt += mp[rem];   

            mp[rem]++;
        }

        return cnt;
    }
};