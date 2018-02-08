class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minCost = INT32_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            minCost = min(minCost, prices[i]);
            res = max(res, prices[i] - minCost);
        }
        return res;
    }
};