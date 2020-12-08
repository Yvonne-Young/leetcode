/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n < 1) {return {};}
        vector<string> res;
        BackTracking("", n, n, n, res);
        return res;
    }

    void BackTracking(string sol, int n, int left, int right, vector<string>& res) {
        if (sol.length() == 2 * n) {
            res.push_back(sol);
            return;
        }
        if (left > 0) {
            BackTracking(sol+'(', n, left - 1, right, res);
        }
        if (right > left) {
            BackTracking(sol+')', n, left, right - 1, res);
        }
    }
};
// @lc code=end

