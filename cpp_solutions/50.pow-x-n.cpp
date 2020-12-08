/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    // Time Limit Exceeded
    // all passed
    /*
    double myPow(double x, int n) {
        double res = 1.0;
        if (x == 0) {return 0;}
        if (x == 1 || n == 0) {return 1;}
        if (x == -1 && n % 2 == 0) {return 1;}
        if (x == -1 && n % 2 == 1) {return -1;}
        if (n == 1) {return x;}
        if (n > 0) {
            for (int i = 0; i < n; i ++) {
                res *= x;
            }
            return res;
        }
        else {
            for (int i = n; i < 0 && res != 0; i ++) {
                res /= x;
            }
            return res;
        }
    }
    */

   // Recursive solution
   // Runtime: 0ms, beats 100%
   // Memory usage: 6.4MB, beats 100%
   double myPow(double x, int n) {
       if (n == 0) {return 1;}
       if (n == 1) {return x;}
       if (n == -1) {return 1 / x;}
       if (n % 2 == 0) {
           return myPow(x * x, n / 2);
       }
       else {
           if (n > 0) {return myPow(x * x, n / 2) * x;}
           else {return myPow(x * x, n / 2) * 1 / x;}
       }
    // return myPow(x * x, n / 2) * (n % 2 == 0 ? 1 : n > 0 ? x : 1 / x);
   } 
};
// @lc code=end

