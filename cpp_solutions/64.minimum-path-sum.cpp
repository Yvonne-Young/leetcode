/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    // Dynamic programming, from top to bottom
    // Runtime: 16ms, beats 87.62%
    // Memory usage: 10.5MB, beats 13.91%
    // The state array is not necessary because we can modify the original grid directly since there
    // is no data dependency
    // The optimized version: 
    // Memory usage: 9.8MB, beats 96.02%
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> state(m, vector<int>(n, 0));
        // state[0][0] = grid[0][0];
        for (int i = 1; i < n; i ++) {
            grid[0][i] = grid[0][i] + grid[0][i - 1];
        }
        for (int j = 1; j < m; j ++) {
            grid[j][0] = grid[j][0] + grid[j - 1][0];
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
// @lc code=end

