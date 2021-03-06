/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    // Runtime: 4ms, beats 90.11%
    // Memory usage: 6.7MB, beats 5.07%
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

    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solveHelper(board, res, n, 0);
        return res.size();
    }
};
// @lc code=end

