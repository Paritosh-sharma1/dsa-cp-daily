#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n =tokens.size(), l=0,r=n-1;
        int points=0,mx=0;
        while(l<=r){
            if(power>=tokens[l]){
                power-=tokens[l];
                points+=1;
                mx=max(mx,points);
                l++;
            }
            else{
                if(points==0){
                    return 0;
                }
                if(points>=1){
                    power+=tokens[r];
                    points-=1;
                    r--;   
                }
            }
        }
        return mx;
        // tc -> O(N)
    }
};