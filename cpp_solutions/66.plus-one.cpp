/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    // Add with each bits to avoid possible integer overflow
    // Runtime: 4ms, beats 55.93%
    // Memory usage: 9.2MB, beats 100%
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> res(digits.size() + 1, 0);
        for (int i = digits.size() - 1; i >= 0; i --) {
            if (carry == 0) {
                res[i + 1] = digits[i];
            }
            else {
                if (digits[i] < 9) {res[i + 1] = digits[i] + 1; carry = 0;}
                else {res[i + 1] = 0; carry = 1;}
            }
        }
        if (carry == 1) {res[0] = 1;}
        else {res.erase(res.begin(), res.begin() + 1);}
        return res;
    }
};
// @lc code=end

