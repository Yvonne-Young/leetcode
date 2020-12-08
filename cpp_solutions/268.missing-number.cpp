/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    // Runtime: 64ms, beats 17.09%
    // Memory usage: 18.4MB, beats 7.84%
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] != 0) {return 0;}
        for (int i = 0; i < nums.size() - 1; i ++) {
            if (nums[i + 1] - nums[i] > 1) {return nums[i] + 1;}
        }
        return nums.size();
    }
};
// @lc code=end

