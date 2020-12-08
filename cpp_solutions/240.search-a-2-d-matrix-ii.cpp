/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    // Traverse over row and use binary search for each row
    // Time complexity: O(MlogN)
    // Runtime: 516ms, beats 9.65%
    // Memory usage: 11MB, beats 96.89%
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {return false;}
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) {return false;}
        for (int i = 0; i < m; i ++) {
            int low = 0; 
            int high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] == target) {return true;}
                if (matrix[i][mid] > target) {high = mid - 1;}
                else {low = mid + 1;}
            }
        }
        return false;
    }

    // Traverse only rows whose first element is smaller than target
    // Reduced Runtime but still O(MlogN)
    // Runtime: 344ms, beats 14.37%
    // Memory usage: 10.8MB, beats 96.89%
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {return false;}
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) {return false;}
        int i = 0; 
        while (i < m && matrix[i][0] <= target) {
            int low = 0;
            int high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] == target) {return true;}
                if (matrix[i][mid] > target) {high = mid - 1;}
                else {low = mid + 1;}
            }
            i ++;
        }
        return false;
    }

    // Zig-zag search, O(M + N), optimal solution!
    // Runtime: 116ms, beats 60.22%
    // Memory usage: 10.9MB, beats 96.89%
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {return false;}
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) {return false;}
        int i = 0; 
        int j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {return true;}
            if (matrix[i][j] > target) {j --;}
            else {i ++;}
        }
        return false;
    }
};
// @lc code=end

