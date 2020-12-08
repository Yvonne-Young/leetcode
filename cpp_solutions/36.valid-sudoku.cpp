/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    // Runtime: 52ms, beats 17.36%
    // Memory usage: 20.6MB, beats 9.92%
    bool isValidSudoku(vector<vector<char>>& board) {
        // check on rows
        for (int i = 0; i < 9; i ++) {
            unordered_map<char, int> ump1;
            for (int j = 0; j < 9 ; j ++) {
                if (board[i][j] != '.')
                    ump1[board[i][j]] ++;
            }
            for (auto c : ump1) {
                if (c.second > 1) {return false;}
            }
        }

        // check on columns
        for (int i = 0; i < 9; i ++) {
            unordered_map<char, int> ump2;
            for (int j = 0; j < 9; j ++) {
                if (board[j][i] != '.')
                    ump2[board[j][i]] ++;
            }
            for (auto c : ump2) {
                if (c.second > 1) {return false;}
            }
        }

        // check on blocks
        for (int k = 0; k < 9; k ++) {
            unordered_map<char, int> ump3;
            for (int i = 3 * (k / 3); i < 3 * (k / 3) + 3; i ++) {
                for (int j = 3 * (k % 3); j < 3 * (k % 3) + 3; j ++) {
                    cout << i << " " << j << '\n';
                    if (board[i][j] != '.')
                        {ump3[board[i][j]] ++;}
                }
            }
            for (auto c : ump3) {
                if (c.second > 1) {return false;}
            }
        }
        return true;
    }
};
// @lc code=end

