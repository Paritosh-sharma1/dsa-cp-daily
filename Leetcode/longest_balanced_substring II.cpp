#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 1, v1 = 0, v2 = 0;
        map<pair<int, int>, int> mp; mp[{0,0}] = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') v1++;
            else if(s[i] == 'c') v2++;
            else {v1--; v2--;}           
            if(!mp.count({v1, v2})) mp[{v1, v2}] = i;
            ans = max(ans, i - mp[{v1, v2}]);
        }
        vector<string> comb = {"ab", "ac", "bc"};
        for(auto c : comb) {
            int x = c[0], y = c[1], v = 0;
            map<int, int> m; m[0] = -1;
            for(int i = 0; i < n; i++) {
                if(s[i] == x) v++;
                else if(s[i] == y) v--;
                else {
                    m.clear(); v = 0;
                }
                if(!m.count(v)) m[v] = i;
                ans = max(ans, i - m[v]);
            }
        }
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }
        return ans;
    }
};