#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        string s1 = "", s2 = "";
        for(char c : start) if(c != '_') s1 += c;
        for(char c : target) if(c != '_') s2 += c;
        if(s1 != s2) return false;
        int i = 0, j = 0;
        while(i < n && j < n){
            while(i < n && start[i] == '_') i++;
            while(j < n && target[j] == '_') j++;
            if(i == n || j == n) break;
            if(start[i] != target[j]) return false;
            if(start[i] == 'L' && i < j) return false;
            if(start[i] == 'R' && i > j) return false;
            i++; j++;
        }
        return true;
    }
};