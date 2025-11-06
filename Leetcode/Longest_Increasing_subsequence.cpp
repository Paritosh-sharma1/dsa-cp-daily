Link: https://leetcode.com/problems/longest-increasing-subsequence/description/


//Memoization
class Solution {
public:

    int solve(int idx,int prev_idx,vector<int>& nums,vector<vector<int>>& dp){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][prev_idx+1]!=-1){
            return dp[idx][prev_idx+1];
        }
        int take = 0;
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            take = 1+ solve(idx+1,idx,nums,dp);
        }
        int notTake = solve(idx+1,prev_idx,nums,dp);
        return dp[idx][prev_idx+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};


//Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int notTake = dp[i+1][j+1];
                int take= 0;
                if(j==-1 || nums[i]>nums[j]){
                    take =1 + dp[i+1][i+1];
                }
                dp[i][j+1]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
};