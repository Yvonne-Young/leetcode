/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    // Runtime: 8ms, beats 61.92%
    // Memory usage: 7MB, beats 40.41%
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "") return -1;
        if (needle.size() > haystack.size()) return -1;
        int n = needle.size();
        int idx = -1;
        bool flag = true;
        for (int i = 0; i <= haystack.size() - n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (haystack[i + j] != needle[j]) {flag = false; break;}
                else {flag = true;}
            }
            if (flag == true) {
                idx = i; 
                break;
            }
        }
        return idx;
    }
};
// @lc code=end

