/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    // Runtime: 4ms, beats 92.28%
    // Memory usage: 7.1MB, beats 16.36%
    string addBinary(string a, string b) {
        // Full Adder logic: 
        // Input:  A, B, Cin
        // Output: S, Cout
        // S = A XOR B XOR Cin
        // Cout = A & B + Cin & (A + B)
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string ans = "";

        while (i >= 0 && j >= 0) {
            int tmp_a = (int) a[i] - 48;
            int tmp_b = (int) b[j] - 48;
            string sum = to_string(tmp_a ^ tmp_b ^ carry);
            ans = sum + ans;
            carry = (tmp_a & tmp_b) | (carry & (tmp_a | tmp_b));
            i --;
            j --;
        }

        // deal with the remaining string
        if (i >= j) {
            // a is no shorter than b
            while (i >= 0) {
                if (carry == 0) {
                    ans = a.substr(0, i + 1) + ans;
                    break;
                }
                else {
                    if (a[i] == '0') {
                        carry = 0;
                        ans = "1" + ans;
                        i --;
                    }
                    else {
                        carry = 1;
                        ans = "0" + ans;
                        i --;
                    }
                }
            }
        }
        else {
            // b is longer than a
            while (j >= 0) {
                if (carry == 0) {
                    ans = b.substr(0, j + 1) + ans;
                    break;
                }
                else {
                    if (b[j] == '0') {
                        carry = 0;
                        ans = "1" + ans;
                        j --;
                    }
                    else {
                        carry = 1;
                        ans = "0" + ans;
                        j --;
                    }
                }
            }
        }
        ans = (carry == 1) ? ("1" + ans) : ans;
        return ans;
    }
};
// @lc code=end

