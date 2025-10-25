Link: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/


class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num){
            return "";
        }
        string ans(num, '0');
        
        for(int i = 0; i < num; i++) {
            if(sum >= 9) {
                ans[i] = '9';
                sum -= 9;
            } else {
                ans[i] = char('0' + sum);
                break;
            }
        }
        return ans;
    }
};
