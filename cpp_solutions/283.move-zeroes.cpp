/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    // Runtime: 12ms, beats 36.13%
    // Memory usage: 9.4MB, beats 100%
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        vector<int>::iterator it = nums.begin();
        while (it != nums.end()) {
            if (*it == 0) {
                it = nums.erase(it);
                count ++;
            }
            else {
                it ++;
            }
        }
        for (int i = 0; i < count; i ++) {
            nums.push_back(0);
        }
    }
};
// @lc code=end

