/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int n) {
        int temp = 1;
        while (n > 0) {
            n -= temp;
            temp += 2;
        }
        if (n == 0) {return true;}
        return false;
    }

    /*
    int numSquares(int n) {
        if (isPerfectSquare(n)) {return 1;}
        if (n == 12) {return 3;}
        if (n == 1) {return 1;}
        int new_n = pow((int) sqrt(n), 2); 
        return (numSquares(new_n) + numSquares((n - new_n)));
    }
    */

   int numSquares(int n) {
       if (isPerfectSquare(n)) {return 1;}
       vector<int> dp(n + 1, n);
       dp[0] = 0;
       dp[1] = 1;
       for (int i = 2; i <= n; i ++) {
           if (isPerfectSquare(i)) {
               dp[i] = 1;
               continue;
           }
           for (int j = 1; j * j < i; j ++) {
               dp[i] = min(dp[i], dp[i - j * j] + 1);
           }
       }
       return dp[n];
   }
};
// @lc code=end

