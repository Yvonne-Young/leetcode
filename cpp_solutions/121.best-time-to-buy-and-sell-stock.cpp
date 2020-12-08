/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        int profit = 0;
        if (prices.size() == 0) {
            return 0;
        }
        for (int i = 0; i < prices.size() - 1; i ++) {
            for (int j = i + 1; j < prices.size(); j ++) {
                if (prices[j] - prices[i] >= profit) {
                    profit = prices[j] - prices[i];
                }
            }
        }
        return profit;
        */
       int max_profit = 0;
       int min_price = INT_MAX;
       for (int i = 0; i < prices.size(); i ++) {
           min_price = min(prices[i], min_price);
           max_profit = max(prices[i] - min_price, max_profit);
       }
       return max_profit;
    }
};
// @lc code=end

