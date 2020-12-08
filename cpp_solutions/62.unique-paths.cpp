/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    // DP, from top to bottom
    // Runtime: 4ms, beats 13.7%
    // Memory usage: 6.9MB, beats 5.87%
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            paths[i][0] = 1;
        }
        for (int j = 0; j < n; j ++) {
            paths[0][j] = 1;
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
        return paths[m - 1][n - 1];
    }
};
// @lc code=end

