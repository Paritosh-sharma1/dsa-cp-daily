Link: https://leetcode.com/problems/merge-adjacent-equal-elements/submissions/1931026511/

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
    stack<long long> st;

    if(nums.empty()) return {};

    st.push(nums[0]);

    for(int i = 1; i < nums.size(); i++) {
        if(!st.empty() && st.top() == nums[i]) {
            long long val = nums[i];

            while(!st.empty() && st.top() == val) {
                val += st.top();
                st.pop();
            }

            st.push(val);
        } 
        else {
            st.push(nums[i]);
        }
    }

    vector<long long> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
    }
};