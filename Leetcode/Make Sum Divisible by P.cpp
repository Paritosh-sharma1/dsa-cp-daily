Link : https://leetcode.com/problems/make-sum-divisible-by-p/description/


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total  =0;
        for(auto i:nums){
            total+=i;
        }

        if(total%p==0){
            return 0;
        }

        map<int,int> mp;

        mp[0]=-1;

        int currentSum=0;
        int target =  total%p;
        int minLen = nums.size();
        for(int i=0;i<nums.size();i++){
            currentSum = (currentSum+nums[i])%p;
            int needed  =  (currentSum-target+p)%p;
            if(mp.find(needed)!=mp.end()){
                minLen= min(minLen,i-mp[needed]);
            }
            mp[currentSum]=i;   
        }
        return minLen ==nums.size() ? -1:minLen; 
    }
};
