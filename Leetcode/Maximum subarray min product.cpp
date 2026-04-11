Link: https://leetcode.com/problems/maximum-subarray-min-product/description/


class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod=1e9+7;
        int n=nums.size();
        vector<long long> pre(n+1, 0);
        for(int i = 0; i < n; i++){
            pre[i+1] = pre[i] + nums[i];
        }
        vector<int> left(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        vector<int> right(n);
        stack<int> st1;

        for(int i = n-1; i >= 0; i--){
            while(!st1.empty() && nums[st1.top()] > nums[i]){
                st1.pop();
            }
            right[i] = st1.empty() ? n : st1.top();
            st1.push(i);
        }

        long long ans = 0;

    for(int i = 0; i < n; i++){
        int l = left[i];
        int r = right[i];

        long long sum = pre[r] - pre[l+1];
        ans = max(ans, sum * nums[i]);
    }
        return ans%mod;
    }
};