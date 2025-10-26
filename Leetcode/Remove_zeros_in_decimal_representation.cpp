Link: https://leetcode.com/problems/remove-zeros-in-decimal-representation/
 
class Solution {
public:
    long long removeZeros(long long n) {
        string a = to_string(n);
        string b="";
        for(int i=0;i<a.size();i++){
            if(a[i]!='0'){
                b+=a[i];
            }
        }
        return stol(b);
    }
};