/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    // Runtime: 4ms, beats 81.34%
    // Memory usage: 9.5MB, beats 100%
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p3 = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] >= nums2[p2]) {
                nums1[p3] = nums1[p1];
                p1 --;
            }
            else {
                nums1[p3] = nums2[p2];
                p2 --;
            }
            p3 --;
        }

        // if nums2 is longer than nums1
        while (p2 >= 0) {
            nums1[p2] = nums2[p2];
            p2 --;
        }
    }
};
// @lc code=end

