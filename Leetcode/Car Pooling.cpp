Link: https://leetcode.com/problems/car-pooling/description/


class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        int n = trips.size();

        std::vector<int> prefix(1001, 0);   

        for (int i = 0; i < n; i++) {
            int inPeople = trips[i][0];     
            prefix[trips[i][1]] += inPeople; 
            prefix[trips[i][2]] -= inPeople; 
        }

        int curr = 0;
        for (int i = 0; i <= 1000; i++) {
            curr += prefix[i];
            if (curr > capacity) return false;
        }
        return true;
    }
};