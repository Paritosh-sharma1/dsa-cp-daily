Link:  https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int  n =security.size();
        
        vector<int> pre(n,0),suf(n,0);

        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1]){
                pre[i]=pre[i-1]+1;
            }
        }
    
        for(int i=n-2;i>=0;i--){
            if(security[i+1]>=security[i]){ 
                suf[i]=1+suf[i+1];
            }
        }
        vector<int> ans;

        for(int i=time;i<n-time;i++){
            if(pre[i]>=time && suf[i]>=time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};