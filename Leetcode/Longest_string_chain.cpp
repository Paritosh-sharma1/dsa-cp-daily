Link: https://leetcode.com/problems/longest-string-chain/description/


class Solution {
public:

    bool compare(string& s1,string& s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int first=0,sec=0;
        while(first<s1.size()){
            if(sec<s2.size() && s1[first]==s2[sec]){
                first++;
                sec++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() &&  sec==s2.size())return true;
        else return false;
    }
    static bool comp(string& s1,string& s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(compare(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};