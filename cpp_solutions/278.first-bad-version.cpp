/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // Binary search, time complexity: O(logn), space complexity: O(1)
    // Runtime: 0ms, beats 100%
    // Memory usage: 6.1MB, beats 99.98%
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
// @lc code=end

