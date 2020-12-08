/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    // Runtime: 56ms, beats 30.4%
    // Memory usage: 7.8MB, beats 51.19%
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) {return true;}
        else {return false;}
    }
};
// @lc code=end

