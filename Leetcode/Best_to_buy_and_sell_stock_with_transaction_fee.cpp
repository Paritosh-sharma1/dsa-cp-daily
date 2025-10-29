Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
public:
    int solve(int i,int fee,vector<int>& arr,vector<vector<int>>& dp,int flag){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i][flag]!=-1){
            return dp[i][flag];
        }
        int buy=0,sell=0;
        if(flag==0){
            buy=max(0+solve(i+1,fee,arr,dp,0),-arr[i]+solve(i+1,fee,arr,dp,1)-fee);
        }
        if(flag==1){
            sell=max(arr[i]+solve(i+1,fee,arr,dp,0),0+solve(i+1,fee,arr,dp,1));
        }
        return dp[i][flag]=max(buy,sell);
    }
    int maxProfit(vector<int>& arr,int fee) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,fee,arr,dp,0);
    }
};