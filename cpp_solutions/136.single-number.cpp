/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    // Solution1: hash map
    // Runtime: 60ms, beats 11.11%
    // Memory usage: 21MB, beats 21.19%
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        std::unordered_map<int, int> mmp;
        for (int i = 0; i < nums.size(); i ++) {
            mmp[nums[i]] ++;
        }
        for (auto m: mmp) {
            if (m.second == 1) {return m.first;}
        }
        return -1;
    }

    // Solution2: bit manipulation
    // 0 XOR a = a
    // Runtime: 24ms, beats 74%
    // Memory usage: 17.3MB, beats 21.19%
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (int i : nums) {
            a ^= i;
        }
        return a;
    }
};
// @lc code=end

