Link: https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
 


class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        if(n<3){
            return 0;
        }
        vector<int>dp1(n,1),dp2(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp1[i]<1+dp1[j]){
                    dp1[i]=1+dp1[j];
                }
            }
        }
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j] && dp2[i]<1+dp2[j]){
                    dp2[i]=1+dp2[j];
                }
            }
        }
        for(int i=0;i<n;i++){
             if (dp1[i] > 1 && dp2[i] > 1) {
                maxi = max(maxi,dp1[i]+dp2[i]-1);    
             }
        }
        return maxi;
    
        
    }
};
