#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int groups = 0;
        std::sort(intervals.begin(), intervals.end());
        // build a minHeap to store the finished time 
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (int i=0; i<intervals.size(); i++) {
            if (minHeap.empty() || intervals[i][0] <= minHeap.top()) {
                // if currInterval overlap the prevInterval, then add new groups
                minHeap.push(intervals[i][1]);
            }
            if (!minHeap.empty() && minHeap.top() < intervals[i][0]) {
                minHeap.pop();
                minHeap.push(intervals[i][1]);
            }
            groups = std::max(groups, (int)minHeap.size());
        }
        return groups;
    }
};