/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    // Variation of Binary search, time complexity O(logN)
    // Runtime: 8ms, beats 88.79%
    // Memory usage: 14.1MB, beats 99.96%
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {return true;}
            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low ++;
                high --;
            }
            // if left half is in ascending order
            else if (nums[low] <= nums[mid]){
                // if target falls under left half
                if (nums[mid] > target && nums[low] <= target) {high = mid - 1;}
                // if target falls under right half
                else {low = mid + 1;}
            }
            // if right half is in ascending order
            else {
                if (nums[mid] < target && nums[high] >= target) {low = mid + 1;}
                else {high = mid - 1;}
            }
        }
        return false;
    }

    // Line scan, simple but when N is large, performance is much worse than binary search
    // Runtime: 12ms, beats 52.14%
    // Memory usage: 14.2MB, beats 99.96%
    bool search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == target) {return true;}
        }
        return false;
    }
};
// @lc code=end

