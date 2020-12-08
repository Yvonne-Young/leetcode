/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    // Bit manipulation, shift and mask
    // Runtime: 4ms, beats 52.1%
    // Memory usage: 6.3MB, beats 60.7%
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int shft = 31; shft >= 0; shft --) {
            ans += (n & 1) << shft;
            n = n >> 1;
        }
        return ans;
    }
};
// @lc code=end

