#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>>minHeap;
        unordered_set<long>seenNumber;
        vector<int>primeFactors ={2,3,5};
        minHeap.push(1);
        seenNumber.insert(1);
        long currentUgly=1;
        for(int i=0;i<n-1;i++){
            currentUgly=minHeap.top();
            minHeap.pop();
            for(auto prime: primeFactors){
                long nextUgly = currentUgly*prime;
                if(seenNumber.find(nextUgly)==seenNumber.end()){
                    minHeap.push(nextUgly);
                    seenNumber.insert(nextUgly);
                }
            }
        }
        return minHeap.top();
    }
};