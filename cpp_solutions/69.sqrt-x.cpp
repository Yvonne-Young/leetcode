/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    // Binary search
    // Runtime: 0ms, beats 100%
    // Memory usage: 6.2MB, beats 100%
    int helper(int x, int low, int high) {
        int mid = (low + high) / 2;
        if ((mid == x / mid) || (mid < x / mid && (mid + 1) > x / (mid + 1))) {return mid;}
        if (mid > x / mid) {return helper(x, low, mid);}
        else {return helper(x, mid, high);}
    }

    int mySqrt(int x) {
        if (x == 0) {return 0;}
        if (x == 1) {return 1;}
        return helper(x, 0, x);
    }
};
// @lc code=end

