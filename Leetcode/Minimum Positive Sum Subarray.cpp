Link : https://leetcode.com/problems/minimum-positive-sum-subarray/description/


class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();

        int mini = INT_MAX;

        vector<int> prefix(n+1,0);

        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
            // cout<<prefix[i]<<" ";
        }
        int i= 1;
        int sum=0;
        for(int j=1;j<=n;j++){
            i=1;
            while(i<=j){
                sum=prefix[j]-prefix[i-1];
                if(j-i+1>=l && j-i+1<=r &&sum>0){
                    mini=min(sum,mini);
                    cout<<mini<<" ";
                }
                i++;
            }
        }
        if(mini<=0 || mini==INT_MAX){
            return -1;
        }else{
            return mini;
        }
    }
};