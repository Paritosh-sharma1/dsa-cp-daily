Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/solutions/5778338/monotonic-stack-to-greedy-solution/?envType=problem-list-v2&envId=dynamic-programming

//  Doing by observation
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];
        for(int i =1;i<n;i++){
            if(target[i]>target[i-1])ans+=(target[i]-target[i-1]);
        }
        return ans;
    }
};
// Doing by Monotonic Stack
class Solution {
public:
    // O(n) time | O(n) space
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int operations = 0;
        stack<pair<int,int>> monostack; // {height, work needed}
        monostack.push({0, 0});

        for (int i = 0; i <= n; ++i) {
            int height = i < n ? target[i] : INT_MAX; // INT_MAX to force stack collapse at end, if needed
            int work = max(0, height - monostack.top().first);
            while (monostack.size() && height > monostack.top().first) {
                operations += monostack.top().second;
                monostack.pop();
            }
            monostack.push({height, work});
        }
        return operations;
    }
};