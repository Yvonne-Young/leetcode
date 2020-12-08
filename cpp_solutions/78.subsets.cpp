/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    // Backtracking
    // Runtime: 4ms, beats 68.08%
    // Memory usage: 7.3MB, beats 7.26%
    void BackTracking(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, int i) {
        res.push_back(tmp);
        for (int j = i; j < nums.size(); j ++) {
            tmp.push_back(nums[j]);
            BackTracking(nums, res, tmp, j + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        BackTracking(nums, res, tmp, 0);
        return res;
    }
};
// @lc code=end

