/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0; 
        int j = s.length() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {return false;}
            i ++; 
            j --;
        }
        return true;
    }

    // Solution1. Backtracking to get all possible partitioning and find the one with minimum cut
    // Same idea as 131. Palindrome Partitioning I. 
    // Time Limit Exceeded when string is large. 24/29 cases passed
    int minCut(string s) {
        vector<vector<string>> all_partitions;
        vector<string> partition;
        int n = s.length();
        BackTracking(partition, all_partitions, s, 0, n);
        
        // traverse through all partitions and found the smallest list
        int min = INT_MAX;
        for (int i = 0; i < all_partitions.size(); i ++) {
            if (all_partitions[i].size() - 1 < min) {min = all_partitions[i].size() - 1;}
        }
        return min;
    }

    void BackTracking(vector<string>& partition, vector<vector<string>>& all_partitions, string s, int i, int n) {
        if (i == n) {all_partitions.push_back(partition); return;}
        for (int j = i; j < n; j ++) {
            if (isPalindrome(s.substr(i, j - i + 1))) {
                partition.push_back(s.substr(i, j - i + 1));
                BackTracking(partition, all_partitions, s, j + 1, n);
                partition.pop_back();
            }
        }
    }
};
// @lc code=end

