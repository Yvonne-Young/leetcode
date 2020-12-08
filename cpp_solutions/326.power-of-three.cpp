/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        /*
        if (n % 3 != 0) return false;
        if (n == 0) return false;
        if (n == 1) return true;
        return isPowerOfThree(n/3);
        */
        int i = 1;
        return n == i ||
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3) || 
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3) || 
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3) || 
               n == (i *= 3) ||
               n == (i *= 3) ||
               n == (i *= 3);
    }
};
// @lc code=end

