Link: https://leetcode.com/problems/number-of-ways-to-split-array/description/


class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;

        // prefix array
        vector<long long> pre(n + 1, 0);

        // safe prefix sum (no overflow)
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i-1] + (long long)nums[i-1];
        }

        long long i = 1;

        while(i < n){
            long long left = pre[i];           
            long long right = pre[n] - pre[i]; 

            if(left >= right){
                cnt++;
            }
            i++;
        }

        return cnt;
    }
};