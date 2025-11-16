Link: https://leetcode.com/problems/maximize-expression-of-three-elements/

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return nums[n-1]+nums[n-2]-nums[0];
    }
};