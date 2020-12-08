/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    // scan the nums and if nums[i + 1] < nums[i] > nums[i - 1], then i is a peak
    // time complexity: O(N), space complexity: O(1)
    // Runtime: 4ms, beats 97.5%
    // Memory usage: 9.1MB, beats 100%
    int findPeakElement(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {return 0;}
        if (nums.size() == 2) {return max(nums[0], nums[1]) == nums[0] ? 0 : 1;}
        if (nums[0] > nums[1]) {return 0;}
        for (int i = 1; i < nums.size() - 1; i ++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {return i;}
        }
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) {return nums.size() - 1;}
        else {return -1;}
    }

    // Binary search, O(logN), this will only work when we make the assumption: nums[-1] = nums[N] = -inf
    // Runtime: 4ms, beats 97.5%
    // Memory usage: 9.2MB, beats 100%
    int findPeakElement(vector<int>& nums) {
        int low = 0; 
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {low = mid + 1;}
            else {high = mid - 1;}
        }
        return low;
    }
};
// @lc code=end

