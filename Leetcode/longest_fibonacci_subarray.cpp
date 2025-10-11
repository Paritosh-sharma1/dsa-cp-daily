#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return 2;
        }
        int maxlen=2,curlen=2;
        for(int i=2;i<n;i++){
            if(nums[i]==nums[i-1]+nums[i-2]){
                curlen++;
            }
            else{
                curlen=2;
            }
            maxlen=max(maxlen,curlen);
        }
        return maxlen;
    }
};