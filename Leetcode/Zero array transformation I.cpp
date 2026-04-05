Link : https://leetcode.com/problems/zero-array-transformation-i/description/


class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        vector<int> freq(n+1,0);

        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];

            freq[l]+=1;
            if(r<n+1)freq[r+1]-=1;
        }
        
        for(int i=1;i<=n;i++){
            freq[i]+=freq[i-1];
        }

    
        for(int i=0;i<nums.size();i++){
            if(nums[i]>freq[i]){
                return false;
            }
        }
        return true;
    }
};