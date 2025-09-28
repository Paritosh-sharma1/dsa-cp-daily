#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        long currentNumber = 1;
        for (int i = 0; i < n; i++) {
            currentNumber = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == currentNumber) {
                pq.pop();
            }
            for (auto prime : primes) {
                if (currentNumber * prime <= INT_MAX) {
                    pq.push(currentNumber * prime);
                } else {
                    break; 
                }
            }
        }
        return (int)currentNumber;
    }
};
