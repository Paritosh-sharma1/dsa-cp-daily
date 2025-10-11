#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool scoreBalance(string s) {
         int total =0;
        for(char c:s){
            total+=(c-'a'+1);
        }
        int left=0;
        for(int i=0;i<s.size()-1;i++){
            left+=(s[i]-'a'+1);
            int right=total-left;
            if(right==left){
                return true;
            }
        }
        return false;
    }
};