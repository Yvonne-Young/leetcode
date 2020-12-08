/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <algorithm>

class Solution {
public:
    /*
    int coinChange(vector<int>& coins, int amount) {
        int res = 0;
        int n = coins.size();
        vector<int> dp(n, 0);
        std::sort(coins.begin(), coins.end());
        if (amount == 0) {return 0;}
        for (int i = coins.size() - 1; i >= 0; i --) {
            if (coins[i] > amount) {continue;}
            else if (amount % coins[i] == 0) {
                res += amount / coins[i];
                amount = amount % coins[i];
                dp[i] = res;
                break;
            }
            else {
                res += amount / coins[i];
                amount = amount % coins[i];
            }
        }
        int smallest = INT_MAX;
        int count = 0;
        for (int i = n - 1; i >= 0; i --) {
            cout << dp[i];
            if (dp[i] == 0) {count ++;}
            if (dp[i] != 0 && dp[i] < smallest) {smallest = dp[i];}
            else {;}
        }
        return (count == n)?-1:smallest;
    }
    */

   // dynamic programming solution: 
   int coinChange(vector<int>& coins, int amount) {
       vector<int> dp(amount + 1, amount + 1);
       dp[0] = 0;
       for (int coin : coins) {
           for (int i = coin; i <= amount; i ++) {
               dp[i] = min(dp[i], dp[i - coin] + 1);
           }
       }
       return dp[amount] > amount ? -1 : dp[amount];
   }
};
// @lc code=end

