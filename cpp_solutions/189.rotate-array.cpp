/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    // Runtime: 8ms, beats 73.64%
    // Memory usage: 10.4MB, beats 99.98%
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i ++) {
            ans[(i + k) % n] = nums[i];
        }
        for (int i = 0; i < n; i ++) {
            nums[i] = ans[i];
        }
    }
};
// @lc code=end

