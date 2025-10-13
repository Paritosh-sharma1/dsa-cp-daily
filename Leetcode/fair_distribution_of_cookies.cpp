#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int i,vector<int>&cookies,vector<int>& dist,int k,int zero_count){
        if(cookies.size()-i<zero_count){
            return INT_MAX;
        }
        if(i==cookies.size()){
            return *max_element(dist.begin(),dist.end());
        }
        int ans=INT_MAX;
        for(int j=0;j<k;j++){
            zero_count-=dist[j]==0?1:0;
            dist[j]+=cookies[i];
            ans=min(ans,dfs(i+1,cookies,dist,k,zero_count));
            dist[j]-=cookies[i];
            zero_count+=dist[j]==0?1:0;
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>dist(k,0);
        return dfs(0,cookies,dist,k,k);
    }
};