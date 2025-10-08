#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& dp,vector<int>days,vector<int> costs,int curday,unordered_set<int> st){
        if(curday>days[days.size()-1]){
            return 0;
        }
        if(st.find(curday)==st.end()){
            return solve(dp,days,costs,curday+1,st);
        }
        if(dp[curday]!=-1){
            return dp[curday];
        }
        int oneDayCost = costs[0]+solve(dp,days,costs,curday+1,st);
        int sevenDayCost = costs[1]+solve(dp,days,costs,curday+7,st);
        int thirtyDayCost = costs[2]+solve(dp,days,costs,curday+30,st);
        return dp[curday] = min(oneDayCost,min(sevenDayCost,thirtyDayCost));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int lastDay = days[n-1];
        vector<int>dp(lastDay+1,-1);
        unordered_set<int>st(days.begin(),days.end());
        return solve(dp,days,costs,1,st);
    }
};