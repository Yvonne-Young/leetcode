/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
class Solution {
public:
    // Runtime: 124ms, beats 11.09%
    // Memory usage: 42.7MB, beats 9.39%
    vector<vector<int>> shift(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> new_grid(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int i_prime = 0;
                if (j == n - 1 && i == m - 1) {i_prime = 0;}
                else if (j == n - 1) {i_prime = i + 1;}
                else {i_prime = i;}
                new_grid[i_prime][(j + 1)%n] = grid[i][j];
            }
        }
        return new_grid;
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for (int i = 0; i < k; i ++) {
            grid = shift(grid);
        }
        return grid;
    }
};
// @lc code=end

