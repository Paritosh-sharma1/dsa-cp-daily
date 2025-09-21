#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();

        for (int l = 0; l < n; l++) {
            // find first index in nums2 where element < nums1[l]
            auto itr = upper_bound(nums2.begin(), nums2.end(), nums1[l], greater<int>());

            // valid j is before itr (so take itr-1)
            if (itr != nums2.begin()) {
                int j = (itr - nums2.begin()) - 1;
                if (j >= l) {
                    ans = max(ans, j - l);
                }
            }
        }
        return ans;
    }
};
