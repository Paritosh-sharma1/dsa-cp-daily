#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            vector<int> al(26, 0);
            for (int j = i; j < n; j++) {
                al[s[j] - 'a']++;
                int freq = 0, cnt = 0;
                for (int k = 0; k < 26; k++) {
                    if (al[k] > 0) {
                        if (freq == 0)
                            freq = al[k];
                        else if (al[k] != freq) {
                            freq = -1;
                            break;
                        }
                    }
                }
                if (freq != -1)
                    maxlen = max(maxlen, j - i + 1);
            }
        }
        return maxlen;
    }
};