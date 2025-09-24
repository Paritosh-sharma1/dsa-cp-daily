#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        int prev2=0,prev1=1;
        for(int i=2;i<=n;i++){
            int cur= prev2+prev1;
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
};