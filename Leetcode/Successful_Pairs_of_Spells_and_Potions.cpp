#include<bits/stdc++.h>
using namespace std;
class Solution {
public:


    int check(int spell, vector<int>& potions, long long success){
        int l=0,r=potions.size()-1;
        while(l<=r){
            int mid =(l+r)/2;
            long long val = 1LL * potions[mid] * spell; 
            if(success<=val){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int idx = check(spells[i],potions,success);
            ans.push_back(potions.size()-idx);
        }
        return ans;
    }
};