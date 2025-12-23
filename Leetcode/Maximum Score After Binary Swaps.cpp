Link: https://leetcode.com/problems/maximum-score-after-binary-swaps/description/


class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long maximumScore=0;
        priority_queue<int>pq;
        for(int i=0;i<s.size();i++){
            pq.push(nums[i]);
            if(!pq.empty() && s[i]=='1'){
                maximumScore += pq.top();
                pq.pop();
            }
        }
        return maximumScore;
    }
};