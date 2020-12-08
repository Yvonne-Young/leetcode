/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    // O(32 * N) shift and mask
    // Runtime: 12ms, beats 17.05%
    // Memory usage: 8.9MB, beats 27.61%
    int count_ones(int num) {
        int cnt = 0;
        int parity = 0;
        for(int i = 0; i < 32; i ++) {
            int tmp = (num & 1) ^ parity;
            if (parity == !tmp) {cnt ++;}
            num = num >> 1;
        }
        return cnt;
    }

    vector<int> countBits(int num) {
        vector<int> bit_count;
        for (int i = 0; i <= num; i ++) {
            int cnt = count_ones(i);
            bit_count.push_back(cnt);
        }
        return bit_count;
    }

    // O(N) for both time and space complexity
    // Runtime: 8ms, beats 70.49%
    // Memory usage: 8.3MB, beats 48.16%
    vector<int> countBits(int num) {
        vector<int> bit_count(num + 1, 0);
        for (int i = 1; i <= num; i ++) {
            // bit_count[i >> 1] get the high bits count
            // i & 1 get the lsb
            bit_count[i] = bit_count[i >> 1] + (i & 1);
        }
        return bit_count;
    }
};
// @lc code=end

