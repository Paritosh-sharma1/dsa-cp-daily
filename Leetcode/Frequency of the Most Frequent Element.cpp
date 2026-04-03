Link:  https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int l=0;
        long long sum=0;
        int ans=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while((long long)nums[i]*(i-l+1)-sum>k){
                sum-=nums[l];
                l++;
            }
            ans=max(ans,(i-l+1));
        }
        return ans;
    }
};