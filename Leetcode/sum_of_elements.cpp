#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int ans=0;
        for(auto [n,cnt]:mp){
            cout<<cnt<<" ";
            if(cnt%k==0){
                ans+=n*cnt;
            }
        }
        return ans;
    }
};