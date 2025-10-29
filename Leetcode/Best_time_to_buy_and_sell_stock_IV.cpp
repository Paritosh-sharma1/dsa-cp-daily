Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int solve(int i,vector<int>& arr,vector<vector<vector<int>>>& dp,int flag,int k){
        if(i==arr.size() || k==0){
            return 0;
        }
        if(dp[i][flag][k]!=-1){
            return dp[i][flag][k];
        }
        int buy=0,sell=0;
        if(flag==0){
            buy=max(0+solve(i+1,arr,dp,0,k),-arr[i]+solve(i+1,arr,dp,1,k));
        }
        if(flag==1){
            sell=max(arr[i]+solve(i+1,arr,dp,0,k-1),0+solve(i+1,arr,dp,1,k));
        }
        return dp[i][flag][k]=max(buy,sell);
    }
    int maxProfit(int j,vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(j+1, -1)));
        return solve(0,arr,dp,0,j);
    }
};