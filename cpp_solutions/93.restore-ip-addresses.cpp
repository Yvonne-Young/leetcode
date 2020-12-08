/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    bool ValidDigit(string s) {
        if (s.length() > 1 && s[0] == '0') {return false;}
        int digit = stoi(s);
        if (digit >= 0 && digit <= 255) {return true;}
        else {return false;}
    }

    // Backtracking solution with DFS
    // Runtime: 4ms, beats 82.11%
    // Memory usage: 6.7MB, beats 66.91%
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.length();
        if (s.size() < 4 || s.size() > 12) {return {};}
        BackTracking(s, 0, "", 0, ans);
        return ans;
    }

    void BackTracking(string s, int idx, string restored_ip, int count, vector<string>& ans) {
        if (count > 4) {return;}
        if (count == 4 && idx == s.length()) {
            ans.push_back(restored_ip);
        }
        else {
            for (int i = 1; i <= 3; i ++) {
                if (idx + i > s.length()) {break;}
                string sub = s.substr(idx, i);
                if (! ValidDigit(sub)) {continue;}
                BackTracking(s, idx + i, restored_ip + sub + (count == 3?"":"."), count + 1, ans);
            }
        }
    }
};
// @lc code=end

