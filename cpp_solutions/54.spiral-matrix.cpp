/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    // void outBound(vector<vector<int>>& matrix, vector<int>& ans) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     if (n == 1 && m == 1) {
    //         ans.push_back(matrix[0][0]);
    //         return;
    //     }
    //     vector<int> tmp(2 * m + 2 * n - 4, 0);
    //     if (m == 1) {
    //         for (int i = 0; i < n; i ++) {tmp[i] = matrix[0][i];}
    //         ans.insert(ans.end(), tmp.begin(), tmp.end());
    //         return;
    //     }
    //     if (n == 1) {
    //         for (int i = 0; i < m; i ++) {tmp[i] = matrix[i][0];}
    //         ans.insert(ans.end(), tmp.begin(), tmp.end());
    //         return;
    //     }
    //     for (int i = 0; i < n; i ++) {
    //         tmp[i] = matrix[0][i];
    //     }
    //     int j = 1;
    //     for(int i = n; i < n + m - 2; i ++) {
    //         tmp[i] = matrix[j][n - 1];
    //         j ++;
    //     }
    //     j = n - 1;
    //     for  (int i = n + m - 2; i < 2 * n + m - 2; i ++) {
    //         tmp[i] = matrix[m - 1][j];
    //         j --;
    //     }
    //     j = m - 2;
    //     for (int i = 2 * n + m - 2; i < 2 * n + 2 * m - 4; i ++) {
    //         tmp[i] = matrix[j][0];
    //     }
    
    //     ans.insert(ans.end(), tmp.begin(), tmp.end());
    // }

    // Runtime: 0ms, beats 100%
    // Memory usage: 7.1MB, beats 20.49%
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // m x n matrix
        // [ [x, x, x, x],
        //   [x, x, x, x],
        //   [x, x, x, x]
        // ]
        if (matrix.size() == 0) {return {};}
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m * n, 0);
        int r1 = 0; 
        int r2 = m - 1;
        int c1 = 0;
        int c2 = n - 1;
        int p = 0;
        while (r1 <= r2 && c1 <= c2) {
            cout << c1 << c2 << r1 << r2 << endl;
            for (int i = c1; i <= c2; i ++) {
                ans[p] = matrix[r1][i];
                p ++;
            }
            if (++ r1 > r2) {break;}
            for (int i = r1; i <= r2; i ++) {
                ans[p] = matrix[i][c2];
                p ++;
            }
            if (-- c2 < c1) {break;}
            for (int i = c2; i >= c1; i --) {
                ans[p] = matrix[r2][i];
                p ++;
            }
            if (-- r2 < r1) {break;}
            for (int i = r2; i >= r1; i --) {
                ans[p] = matrix[i][c1];
                p ++;
            }
            if (c1 ++ > c2) {break;}
        }
        return ans;
    }
};
// @lc code=end

