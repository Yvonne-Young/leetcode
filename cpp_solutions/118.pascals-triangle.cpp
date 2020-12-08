/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    // Runtime: 0ms, beats 100%
    // Memory usage: 7MB, beats 67.87%
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) {return res;}
        if (numRows == 1) {
            res.push_back({1});
            return res;
        }
        if (numRows == 2) {
            res.push_back({1});
            res.push_back({1,1});
            return res;
        }
        res.push_back({1});
        res.push_back({1,1});
        for (int i = 2; i < numRows; i ++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < i; j ++) {
                tmp.push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

