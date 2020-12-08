/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    // Runtime: 0ms, beats 100%
    // Memory usage: 6.6MB, beats 64.32%
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {return {1};}
        if (rowIndex == 1) {return {1, 1};}
        vector<int> res(rowIndex + 1, 1);
        vector<int> tmp(rowIndex + 1, 1);
        for (int i = 2; i < rowIndex; i ++) {
            for (int j = 1; j < i; j ++) {
                res[j] = tmp[j - 1] + tmp[j];
            }
            for (int i = 0; i < rowIndex; i ++) {
                tmp[i] = res[i];
            }
        }
        for (int i = 1; i < rowIndex; i ++) {
            res[i] = tmp[i - 1] + tmp[i];
        }
        return res;
    }
};
// @lc code=end

