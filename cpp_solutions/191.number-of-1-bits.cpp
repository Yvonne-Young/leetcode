/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    // Bit manipulation, XOR each bit of n and get the parity
    // If the parity toggle, then count ++
    // Runtime: 4ms, beats 46.74%
    // Memory usage: 6.4MB, beats 22.12%
    int hammingWeight(uint32_t n) {
        uint32_t parity = 0;
        int cnt = 0;
        for (int i = 0; i < 32; i ++) {
            int tmp = parity ^ (n & 1);
            if (tmp == !parity) {
                cnt ++;
            }
            parity = tmp;
            n = n >> 1;
        }
        return cnt;
    }
};
// @lc code=end

