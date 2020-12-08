/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    // Fibonacci number solution
    // Iterative solution: 
    // Runtime: 0ms, beats 100%
    // Memory usage: 6.2MB, beats 33.15%
    // The recursive solution meets the time limits
    int climbStairs(int n) {
        if (n == 1) {return 1;}
        if (n == 2) {return 2;}
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i ++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
        // return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
// @lc code=end

