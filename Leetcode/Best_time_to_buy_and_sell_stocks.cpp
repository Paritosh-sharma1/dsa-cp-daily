Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1814866384/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            profit=max(profit,prices[i]-buy);
            buy=min(buy,prices[i]);
        }
        return profit;
    }
};