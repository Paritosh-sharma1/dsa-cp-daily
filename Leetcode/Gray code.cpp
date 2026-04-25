Link: https://leetcode.com/problems/gray-code/description/



// using formula i^(1>>i)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(n);

        for(int i=0;i<(1<<n);i++){
            ans.push_back(i^(1>> i));
        }
        return ans;
    }
};


// using pattern 

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans={0};    
        for(int i=0;i<n;i++){
            int size=ans.size();
            for(int j=size-1;j>=0;j--){
                ans.push_back(ans[j]|(1<<i ));
            }
        }
        return ans;
    }
};