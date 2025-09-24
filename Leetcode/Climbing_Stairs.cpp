#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Memoization
    int solve(int i,vector<int>& dp){
        if(i==0 || i==1){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = solve(i-1,dp);
        int right = solve(i-2,dp);
        return dp[i]=left+right;// all ways to reach a index i 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // return solve(n,dp); 
        
        // Tabulation
        dp[0]=dp[1]=1;
        for(int i=2;i<n+1;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        // return dp[n];  

        // Space Optimization 
        int prev2=1,prev1=1;
        for(int i=2;i<n+1;i++){
            int cur = prev2+prev1;
            prev2=prev1;
            prev1=cur;
        }
        return prev1; 
    }
    
};