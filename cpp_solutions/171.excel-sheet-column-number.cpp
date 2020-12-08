/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    // Runtime: 0ms, beats 100%
    // Memory usage: 6.7MB, beats 9.24%
    int titleToNumber(string s) {
        int val = 0;
        for (int i = 0; i < s.length(); i ++) {
            val += (pow(26, i) * (s[s.length() - 1 - i] - 'A' + 1));
        }
        return val;
    }
};
// @lc code=end

