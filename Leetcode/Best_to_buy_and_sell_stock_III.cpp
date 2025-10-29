Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

//Memoization
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
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(0,arr,dp,0,2);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& Arr) {
        int n=Arr.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 0) { 
                        dp[ind][buy][cap] =
                            max(0 + dp[ind + 1][0][cap],
                                -Arr[ind] + dp[ind + 1][1][cap]);
                    }

                    if (buy == 1) { 
                        dp[ind][buy][cap] =
                            max(0 + dp[ind + 1][1][cap],
                                Arr[ind] + dp[ind + 1][0][cap - 1]);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};