Link: https://leetcode.com/problems/arithmetic-slices/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        
        int cnt = 0;
        int l = 0;
        int prev = nums[1] - nums[0];

        for(int r = 2; r < n; r++){
            int diff = nums[r] - nums[r-1];

            if(diff != prev){
                l = r - 1; 
                prev = diff; 
            }

            if(r - l + 1 >= 3){
                cnt += (r - l + 1) - 2;
            }
        }
        return cnt;
    }
};
