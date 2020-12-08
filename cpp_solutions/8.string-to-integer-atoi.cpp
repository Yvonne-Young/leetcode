/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        map<char, int> digits = {
        {'-', -1},
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9}
        };

        int res = 0;
        int sign = 0;
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] == ' ') {;}
            else if (str[i] == '-') {sign = 1;}
            else if (str[i] == '+') {;}
            else if (digits.find(str[i]) != digits.end()) {break;}
            else {return 0;}
        }

        int count = 0;
        for (int i = str.length() - 1; i >= 0; i --) {
            if (count < 9) {
                if (str[i] == '1' || str[i] == '2' || str[i] == '3' ||
                    str[i] == '4' || str[i] == '5' || str[i] == '6' ||
                    str[i] == '7' || str[i] == '8' || str[i] == '9') {
                    res = res + pow(10, count) * digits[str[i]];
                    count ++;
                }
                else if (str[i] == '.') {res = 0; count = 0;}
            }
            if ((str[i] == 4 && count == 9 && sign == 0 && res >= 294967295) || 
                (str[i] > 4  && count == 9 && sign == 0)) {return INT_MAX;}
            if ((str[i] == 2 && count == 9 && sign == 1 && res >= 147) ||
                (str[i] > 2  && count == 9 && sign == 1)) {return INT_MIN;}
        }

        res = (sign == 1) ? ((-1) * res) : res;

        return res;
    }
};
// @lc code=end

