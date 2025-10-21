Link: https://leetcode.com/problems/valid-parenthesis-string/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int opencount=0,closecount=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='*'){
                opencount++;
            }
            else{
                opencount--;
            }
            if(s[n-i-1]==')'|| s[n-i-1]=='*'){
                closecount++;
            }
            else{
                closecount--;
            }
            if(opencount<0 || closecount<0){
                return false;
            }
        }
        return true;
    }
};