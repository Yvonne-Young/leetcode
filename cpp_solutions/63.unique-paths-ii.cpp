/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    // DP, from top to bottom
    // Runtime: 4ms, beats 92.55%
    // Memory usage: 8.1MB, beats 51.3%
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> paths(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            if (obstacleGrid[i][0] == 1) {
                for (int j = i; j < m; j ++) {
                    paths[j][0] = 0;
                }
                break;
            }
            else {
                paths[i][0] = 1;
            }
        }
        for (int j = 0; j < n; j ++) {
            if (obstacleGrid[0][j] == 1) {
                for (int i = j; i < n; i ++) {
                    paths[0][i] = 0;
                }
                break;
            }
            else {
                paths[0][j] = 1;
            }
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (obstacleGrid[i][j] == 1) {
                    paths[i][j] = 0;
                }
                else {
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                }
            }
        }
        return paths[m - 1][n - 1];
    }
};
// @lc code=end

