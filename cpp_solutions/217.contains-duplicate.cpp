/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    // Hash map, O(N)
    // Runtime: 72ms, beats 35.07%
    // Memory usage: 21.9MB, beats 11.49%
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        for (int i : nums) {
            nums_map[i] ++;
        }
        for (auto m : nums_map) {
            if (m.second > 1) {return true;}
        }
        return false;
    }
};
// @lc code=end

