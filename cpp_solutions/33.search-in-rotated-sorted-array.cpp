/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    // The simplest solution, traverse the array, O(N)
    // Runtime: 4ms, beats 92.11%
    // Memory usage: 11.5Mb, beats 18.79%
    int search(vector<int> nums, int target) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    // Binary search, O(logN)
    // Runtime: 4ms, beats 92.11%
    // Memory usage: 11.5MB, beats 19.79%
    int search(vector<int>& nums, int target) {
        int low = 0; 
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high]) {low = mid + 1;}
            else {high = mid;}
        }
        int pivot = low;
        low = 0;
        high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int realmid = (pivot + mid) % nums.size();
            if (nums[realmid] == target) {return realmid;}
            if (nums[realmid] < target) {low = mid + 1;}
            else {high = mid - 1;}
        }
        return -1;
    }
};
// @lc code=end

