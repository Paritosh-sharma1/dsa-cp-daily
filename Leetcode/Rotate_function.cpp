class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0ll);
        int prod=0;
        for(int i=0;i<nums.size();i++){
            prod+=(i*nums[i]);
        }   
        int n=nums.size();
        int cur=0;
        int maxi=prod;
        for(int i=0;i<nums.size();i++){
            cur = prod+sum-n*nums[n-i];
            maxi=max(cur,maxi);
            prod=cur;a
        }
        return maxi;
    }
};