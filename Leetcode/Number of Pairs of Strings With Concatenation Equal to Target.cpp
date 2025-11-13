Link: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/


class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i!=j){
                    string temp = nums[i] +nums[j];;
                    if(temp == target){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};