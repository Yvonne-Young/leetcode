/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    // Greedy algorithm
    // Runtime: 20ms, beats 72.49%
    // Memory usage: 15.7MB, beats 48.76%
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {return 0;}
        int max_pos = nums[0];
        int max_step = nums[0];
        int jumps = 1;
        int i = 1;
        while (i < n) {
            if (max_step < i) {
                jumps ++;
                max_step = max_pos;
            }
            max_pos = max(max_pos, nums[i] + i);
            i ++;
        }
        return jumps;
    }
};
// @lc code=end

