Link:https://leetcode.com/problems/lexicographically-smallest-string-after-reverse/

class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        string temp;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            temp = s;
            reverse(temp.begin(), temp.begin() + i + 1);
            if (temp < ans) {
                ans = temp;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            temp = s;
            reverse(temp.begin() + i, temp.end());
            if (temp < ans) {
                ans = temp;
            }
        }
        return ans;
    }
};