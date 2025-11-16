Link: https://leetcode.com/problems/minimum-string-length-after-balanced-removals/description/


class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a = count(s.begin(), s.end(), 'a');
        int b = count(s.begin(), s.end(), 'b');
        return abs(a - b);
    }
};
