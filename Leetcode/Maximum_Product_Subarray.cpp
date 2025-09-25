#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN,n=nums.size();
        int prefix =1,suffix=1;
        for(int i=0;i<n;i++){
            if(suffix==0){
                suffix=1;
            }
            if(prefix==0){
                prefix=1;
            }
            prefix *= nums[i];
            suffix *= nums[n-1-i];
            maxi=max(maxi,max(suffix,prefix));
        }
        return maxi;
    }
};