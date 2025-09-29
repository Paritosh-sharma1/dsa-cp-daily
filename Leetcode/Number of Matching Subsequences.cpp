#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> ind(26);
    for(int i=0;i<s.size();i++){
        ind[s[i]-'a'].push_back(i);
    }
    int cnt=0;
    for(auto& word:words){
        bool flag=true;
        int x=-1;
        for(auto& c:word){
            auto it = upper_bound(ind[c-'a'].begin(),ind[c-'a'].end(),x);
            if(it==ind[c-'a'].end()){
                flag=false;
                break;
            }
            else x=*it;
        }
        if(flag){
            cnt++;
        }
    }
    return cnt;
    }
};