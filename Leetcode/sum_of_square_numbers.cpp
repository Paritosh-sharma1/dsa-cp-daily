#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l=0,r = sqrt(c);
        while(l<=r){
            long long val = (l*l) +(r*r);
            if(val==c){
                return true;
            }
            else if(val>c){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};