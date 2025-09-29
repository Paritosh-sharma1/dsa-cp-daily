#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> suffix(n), prefix(n);
        unordered_map<char, int> mp;
        prefix[0] = 1;
        mp[s[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (mp.find(s[i]) == mp.end()) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
            mp[s[i]] = 1;
        }
        mp.clear();
        suffix[n - 1] = 1;
        mp[s[n - 1]] = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (mp.find(s[i]) == mp.end()) {
                suffix[i] = suffix[i + 1] + 1; 
            } else {
                suffix[i] = suffix[i + 1];
            }
            mp[s[i]] = 1; 
        }
        int cnt = 0;
        for (int i = 0; i < n-1 ; i++) {
            if (suffix[i+1] == prefix[i ]) {
                cnt++;
            }
        }
    return cnt;
}
}
;