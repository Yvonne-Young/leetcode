/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    // Runtime: 4ms, beats 92.37%
    // Memory usage: 6.7MB, beats 42.3%
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n - 1;
        int len = 0;
        while (i >= 0) {
            // ignore the trailing spaces
            if (s[i] == ' ') {i --;}
            else {break;}
        }
        while (i >= 0 && s[i] != ' ') {
            // start with the first non-space character
            len ++;
            i --;
        }
        return len;
    }
};
// @lc code=end

