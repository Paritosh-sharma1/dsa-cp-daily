Link: https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1

class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n,1),hash(n);
        int lastindex=0;
        int maxi=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev] && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[i];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastindex=i;
            }
        }
        vector<int>temp;
        temp.push_back(arr[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            temp.push_back(arr[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};