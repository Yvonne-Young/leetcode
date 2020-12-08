/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    // Runtime: 0ms, beats 100%
    // Memory usage: 6.4MB, beats 100%
    string convertToTitle(int n) {
        string ans = "";
        n -= 1;
        ans.push_back(char('A' + n % 26));
        n /= 26;
        while (n != 0) {
            n -= 1;
            ans.insert(ans.begin(), char(n % 26 + 'A'));
            n /= 26;
        }
        return ans;
    }
};
// @lc code=end

