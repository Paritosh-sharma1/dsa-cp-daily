#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
        vector<int> res(n);
        multiset<int> s(nums1.begin(), nums1.end());
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++) arr.push_back({nums2[i], i});
        sort(arr.begin(), arr.end());

        for (int i = n - 1; i >= 0; i--) {
            int val = arr[i].first, idx = arr[i].second;
            
            auto it = s.upper_bound(val); 
            if (it != s.end()) {
                res[idx] = *it;
                s.erase(it);
            } else {
                res[idx] = *s.begin();
                s.erase(s.begin());
            }
        }
        return res;
    }
};