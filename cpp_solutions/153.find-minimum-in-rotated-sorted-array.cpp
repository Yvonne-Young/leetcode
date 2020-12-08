/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    // same as 33. search in rotated sorted array
    // Runtime: 4ms, beats 92.08%
    // Memory usage: 10.4MB, beats 18.21%
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid < n - 1 && nums[mid] > nums[high]) {low = mid + 1;}
            else {high = mid;}
        }
        return nums[low];
    }
};
// @lc code=end

