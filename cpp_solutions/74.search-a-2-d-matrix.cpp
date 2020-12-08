/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    /*
    // This solution uses two binary search
    //     - search on which row the target is at
    //     - search on which col the target is at
    // Time complexity: O(logM + logN)
    // Runtime; 8ms, beats 62.29%
    // Memory usage: 9.8MB, beats 10.52%
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {return false;}
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) {return false;}
        int row = 0;
        // binary search on which row to search further
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = (low + high) / 2; // can use: mid = start + (end - start) / 2 to avoid possible overflow on (low + high)
            if (matrix[mid][0] == target) {return true;}
            if (matrix[mid][0] > target) {high = mid - 1;}
            else {low = mid + 1;}
        }
        row = low > 1 ? low - 1 : 0;

        // binary search on which col target is at
        low = 0; 
        high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[row][mid] == target) {return true;}
            if (matrix[row][mid] > target) {high = mid - 1;}
            else {low = mid + 1;}
        }
        return false;
    }
    */

    // Only use one binary search, working on indexes
    // Runtime: 12ms, beats 21.96%
    // Memory usage: 9.9MB, beats 10.52%
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {return false;}
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) {return false;}
        int low = 0; 
        int high = m * n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid / n][mid % n] == target) {return true;}
            if (matrix[mid / n][mid % n] > target) {high = mid - 1;}
            else {low = mid + 1;}
        }
        return false;
    }
};
// @lc code=end

