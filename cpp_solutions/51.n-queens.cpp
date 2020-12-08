/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    // Runtime: 8ms, beats 84.05%
    // Memory usage: 7.5MB, beats 6.56%
    bool isSafe(vector<string>& board, int row, int col, int n) {
        for (int c = 0; c < col; c ++) {
            if (board[row][c] == 'Q') {return false;}
        }
        int i = row - 1; 
        int j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {return false;}
            i --;
            j --;
        }
        i = row + 1;
        j = col - 1;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q') {return false;}
            i ++;
            j --;
        }
        return true;
    }

    void solveHelper(vector<string>& board, vector<vector<string>>& res, int n, int col) {
        if (col == n) {
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row ++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solveHelper(board, res, n, col + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solveHelper(board, res, n, 0);
        return res;
    }
};
// @lc code=end

