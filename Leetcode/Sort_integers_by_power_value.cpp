Link: https://leetcode.com/problems/sort-integers-by-the-power-value/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    map<int,int>dp;
    int solve(int x){
        if(x==1){
            return 0;
        }
        if(dp.count(x)){
            return dp[x];
        }
        int cnt=0;
        if(x%2==0){
            cnt= 1+solve(x/2);
        }
        else{
            int val =((3*x)+1);
            cnt = 1+ solve(val);
        }
        return dp[x]=cnt;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v; 
        for (int i = lo; i <= hi; i++) {
            int p = solve(i);
            v.push_back({p, i});
        }
        sort(v.begin(), v.end()); 
        return v[k-1].second; 
    }
};