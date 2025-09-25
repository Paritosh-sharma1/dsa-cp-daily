#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int x) {
        int s = sqrt(x);
        return s*s == x;
    }
    
    int numSquares(int n) {
        // Step 1: Check 1 square
        if (isPerfectSquare(n)) return 1;
        
        // Step 2: Check 2 squares
        for (int i = 1; i*i <= n; i++) {
            if (isPerfectSquare(n - i*i)) return 2;
        }
        
        // Step 3: Check if n is of form 4^a*(8b+7)
        int tmp = n;
        while (tmp % 4 == 0) tmp /= 4;
        if (tmp % 8 == 7) return 4;
        
        // Step 4: Otherwise, 3 squares
        return 3;
    }
};
