Link:  https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int sumToFind = totalSum - x;
        if (sumToFind < 0) return -1;

        int maxLength = -1;

        int r = 0;
        int sum = 0;  

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];  

            while (sum > sumToFind && r <= i) {
                sum -= nums[r];  
                r++;
            }

            if (sum == sumToFind) {
                maxLength = max(maxLength, i - r + 1);  
            }
        }

        return maxLength == -1 ? -1 : nums.size() - maxLength;  
    }
};
