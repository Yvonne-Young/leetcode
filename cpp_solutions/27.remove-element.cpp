/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    // Runtime: 4ms, beats 65.94%
    // Memory usage: 9MB, beats 39.65%
    int removeElement(vector<int>& nums, int val) {
        int p = 0;
        while (p < nums.size()) {
            if (nums[p] == val) {nums.erase(nums.begin() + p);}
            else {p ++;}
        }
        return nums.size();
    }
};
// @lc code=end

