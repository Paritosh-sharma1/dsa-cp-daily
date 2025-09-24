#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size();
        string s1 = "", s2 = "";
        for(char c : start) if(c != 'X') s1 += c;
        for(char c : result) if(c != 'X') s2 += c;
        if(s1 != s2) return false;
        int i = 0, j = 0;
        while(i < n && j < n){
            while(i < n && start[i] == 'X') i++;
            while(j < n && result[j] == 'X') j++;
            if(i == n || j == n) break;
            if(start[i] != result[j]) return false;
            if(start[i] == 'L' && i < j) return false;
            if(start[i] == 'R' && i > j) return false;
            i++; j++;
        }
        return true;
    }
};
