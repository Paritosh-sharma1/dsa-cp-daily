Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/


class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;

        for (int i = 0; i < 32; i++) {
            bool bitA = a & (1 << i);
            bool bitB = b & (1 << i);
            bool bitC = c & (1 << i);

            if (bitC) {
                if (!bitA && !bitB) cnt++;
            } else {
                if (bitA && bitB) cnt += 2;
                else if (bitA || bitB) cnt++;
            }
        }
        return cnt;
    }
};