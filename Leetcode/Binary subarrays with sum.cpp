Link: https://leetcode.com/problems/binary-subarrays-with-sum/description/


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int curSum =0;
        map<int,int>mp;
        mp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            curSum+=nums[i];
            if(mp.count(curSum-goal)){
                cnt+=mp[curSum-goal];
            }
            mp[curSum]++;
        }
        return cnt;
    }
};