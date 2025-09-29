#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // increasing
                    if (rating[i] < rating[j] && rating[j] < rating[k]) count++;
                    // decreasing
                    if (rating[i] > rating[j] && rating[j] > rating[k]) count++;
                }
            }
        }

        return count;
    }
};