/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 */

// @lc code=start
class Solution {
public:
    // DFS searching
    // Use a vector to track if one person has been visited, if not, do DFS
    // Runtime: 44ms, beats 89.05%
    // Memory usage: 14.1MB, beats 5.02%
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int count = 0;
        if (n == 0) {return 0;}
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                DFS(M, i, visited);
                count ++;
            }
        }
        return count;
    }

    void DFS(vector<vector<int>>& M, int i, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < M.size(); j ++) {
            if (M[i][j] == 1 && !visited[j] && i != j) {
                DFS(M, j, visited);
            }
        }
    }
};
// @lc code=end

