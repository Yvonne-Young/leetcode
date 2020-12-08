/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    // Dynamic programming, from bottom to top
    // Runtime: 8ms, beats 89.21%
    // Memory usage: 8.9MB, beats 53.93%
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {return INT_MIN;}
        int n = triangle.size();
        if (n == 1) {return triangle[0][0];}
        if (n == 2) {
            return triangle[0][0] + min(triangle[1][0], triangle[1][1]);
        }
        else {
            for (int i = n - 2; i > 0; i --) {
                for (int j = 0; j < i + 1; j ++) {
                    triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                }
            }
            triangle[0][0] += min(triangle[1][0], triangle[1][1]);
        }
        return triangle[0][0];
    }
};
// @lc code=end

