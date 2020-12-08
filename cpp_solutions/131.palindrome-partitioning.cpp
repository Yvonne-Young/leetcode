/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    // BackTracking
    // Runtime: 32ms, beats 66.54%
    // Memory usage: 16.1MB, beats 5.04%
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0; 
        int j = n - 1;
        while (i < j) {
            if (s[i] != s[j]) {return false;}
            i ++; 
            j --;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> partition;
        int n = s.length();
        BackTracking(partition, res, 0, n, s);
        return res;
    }

    void BackTracking(vector<string>& partition, vector<vector<string>>& res, int i, int n, string s) {
        if (i == n) {res.push_back(partition); return;}
        for (int j = i; j < n; j ++) {
            if (isPalindrome(s.substr(i, j - i + 1))) {
                partition.push_back(s.substr(i, j - i + 1));
                BackTracking(partition, res, j + 1, n, s);
                partition.pop_back();
            }
        }
    }
};
// @lc code=end

