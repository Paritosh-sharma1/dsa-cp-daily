class Solution {
public:
    int solve(int idx,int tar,vector<vector<int>>& dp,vector<int>& arr){
        if(idx==arr.size()){
            return tar==0;
        }
        if(tar==0){
            return true;
        }
        if(dp[idx][tar]!=-1){
            return dp[idx][tar];
        }
        int pick =0;
        if(arr[idx]<=tar){
            pick = solve(idx+1,tar-arr[idx],dp,arr);
        }
        int notpick = solve(idx+1,tar,dp,arr);
        return dp[idx][tar]=pick || notpick;
    }
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }  
        if(sum%2!=0){
            return false;
        } 
        int tar = sum/2;
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        return solve(0,tar,dp,arr);
    }
};