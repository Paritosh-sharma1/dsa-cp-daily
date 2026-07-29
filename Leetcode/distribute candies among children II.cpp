Link : https://leetcode.com/problems/distribute-candies-among-children-ii/




class Solution {
public:
    long long ways(long long rem) {
        if (rem < 0) return 0;
        return (rem + 2) * (rem + 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        long long total = 0;
        
        long long S0 = ways(n);
        
        long long S1 = 3 * ways(n - (limit + 1));
        
        long long S2 = 3 * ways(n - 2LL * (limit + 1));
        
        long long S3 = ways(n - 3LL * (limit + 1));
        
        total = S0 - S1 + S2 - S3;
        
        return total;
    }
};