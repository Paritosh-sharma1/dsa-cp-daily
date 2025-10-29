Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//Memoization
class Solution {
public:
    int solve(int i,vector<int>& arr,vector<vector<int>>& dp,int flag){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i][flag]!=-1){
            return dp[i][flag];
        }
        int buy=0,sell=0;
        if(flag==0){
            buy=max(0+solve(i+1,arr,dp,0),-arr[i]+solve(i+1,arr,dp,1));
        }
        if(flag==1){
            sell=max(arr[i]+solve(i+1,arr,dp,0),0+solve(i+1,arr,dp,1));
        }
        return dp[i][flag]=max(buy,sell);
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,arr,dp,0);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j = 0;j<=1;j++){
                int buy = 0,sell=0;
                if(j==0){
                    buy=max(dp[i+1][0],-arr[i]+dp[i+1][1]);
                }
                if(j==1){
                    sell=max(arr[i]+dp[i+1][0],dp[i+1][1]);
                }
                dp[i][j]=max(buy,sell);
            }
        }
        return dp[0][0];
    }
};