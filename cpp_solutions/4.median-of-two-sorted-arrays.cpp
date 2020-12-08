/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    // brute force, use a new array to store nums1 and nums2 together
    // sort the new array, get the median
    // Time complexity: O(m + n + (m + n)*log(m + n))
    // Runtime: 40ms, beats 79.46%
    // Memory usage: 89.7MB, beats 40.55%
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums3(m + n, 0);
        for (int i = 0; i < m; i ++) {
            nums3[i] = nums1[i];
        }
        for (int i = m; i < m + n; i ++) {
            nums3[i] = nums2[i - m];
        }
        sort(nums3.begin(), nums3.end());
        if ((m + n) % 2 == 0) {return (nums3[(m + n) / 2 - 1] + nums3[(m + n) / 2]) / 2.0;}
        else {return (double)nums3[(m + n) / 2];}
    }

    // binary search, O(log(min(m, n)))
    // First find a partition so that each of the left element is smaller than each element in the right half
    // To find the partition, use binary search
    // Once found the partition, return median
    // Runtime: 32ms, beats 95.73%
    // Memory usage: 89.4MB, beats 40.55%
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0; 
        int high = m;
        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            int maxLeftX = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int maxLeftY = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRightX = (partition1 == m) ? INT_MAX : nums1[partition1];
            int minRightY = (partition2 == n) ? INT_MAX : nums2[partition2];
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return (double) (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                }
                else {
                    return (double) max(maxLeftX, maxLeftY);
                }
            }
            else if (maxLeftX > minRightY) {
                high = partition1 - 1;
            }
            else {
                low = partition1 + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

