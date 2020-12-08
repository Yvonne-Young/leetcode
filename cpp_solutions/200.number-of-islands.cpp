/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
private: 
    // Runtime: 20ms, beats 97.93%
    // Memory usage: 10MB, beats 5.11%
    // Traverse the grid and if find a '1':
    //   set it to '0'
    //   set all the direct connected or in-direct connected '1' to '0'
    //   This can use DFS
    void DFS(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        if (x > 0 && grid[x - 1][y] == '1') {
            DFS(grid, x - 1, y);
        }
        if (x < grid.size() - 1 && grid[x + 1][y] == '1') {
            DFS(grid, x + 1, y);
        }
        if (y > 0 && grid[x][y - 1] == '1') {
            DFS(grid, x, y - 1);
        }
        if (y < grid[0].size() - 1 && grid[x][y + 1] == '1') {
            DFS(grid, x, y + 1);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        if (n == 0 || m == 0) {return 0;}
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    islands ++;
                    DFS(grid, i, j);
                }
            }
        }
        return islands;
    }
};
// @lc code=end

