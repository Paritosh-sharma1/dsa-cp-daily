Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/description/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        for(int i=1;i<=100;i++){
            int val =k*i;
            if(mp.find(val)==mp.end()){
                return val;
            }
        }
        return 101;
    }
};