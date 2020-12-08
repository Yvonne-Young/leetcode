/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    map<char, string> digit_map{
        {'2' , "abc"},
        {'3' , "def"},
        {'4' , "ghi"},
        {'5' , "jkl"},
        {'6' , "mno"},
        {'7' , "pqrs"},
        {'8' , "tuv"},
        {'9' , "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {return {};}
        string combinition(digits.length(), ' ');
        BackTracking(digits, combinition, 0, res);
        return res;
    }

    void BackTracking(string digits, string& combinition, int idx, vector<string>& res) {
        if (idx == digits.length()) {
            res.push_back(combinition);
            return ;
        }
        for (char c : digit_map[digits[idx]]) {
            combinition[idx] = c;
            BackTracking(digits, combinition, idx + 1, res);
        }
    }
};
// @lc code=end

