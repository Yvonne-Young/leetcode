/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    // Two pointers, one traverse from front to end, the other one from end to front
    // Runtime: 16ms, beats 83.93%, O(N)
    // Memory usage: 14.2MB, beats 100%
    vector<int> searchRange(vector<int>& nums, int target) {
        int p1; 
        int p2;
        vector<int> ans(2, -1);
        for (p1 = 0; p1 < nums.size(); p1 ++) {
            if (nums[p1] == target) {break;}
        }
        for (p2 = nums.size() - 1; p2 >= 0; p2 --) {
            if (nums[p2] == target) {break;}
        }
        if (p1 > p2) {return {-1, -1};}
        ans[0] = p1;
        ans[1] = p2;
        return ans;
    }

    
};
// @lc code=end

