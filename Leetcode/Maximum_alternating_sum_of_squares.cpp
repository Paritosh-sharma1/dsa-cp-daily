Link: https://leetcode.com/problems/maximum-alternating-sum-of-squares/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]*=-1;
            }
        }
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        long long ans=0;
        while(i<j){
            ans+=(nums[j]*nums[j])-(nums[i]*nums[i]);
            cout<<i<<" "<<j;
            i++;j--;
        }
        if(n%2!=0){
            int i=n/2;
            ans+=nums[i]*nums[i];
        }
        return ans;
    }
};