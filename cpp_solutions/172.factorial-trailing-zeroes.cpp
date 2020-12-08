/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int factorial(int number) {
        if (number == 0) {return 1;}
        if (number == 1) {return 1;}
        else {return (factorial(number - 1) * number);}
    }

    int trailingZeroes(int n) {
        /* This solution will cause integer overflow
        int zeros = 0;
        int f = factorial(n);
        string s = to_string(f);
        cout << s << endl;
        for (int i = s.length() - 8; i > 0; i --) {
            if (s[i] == '0') {
                zeros ++;
            }
            else {break;}
        }    
        return zeros; */
        int zeros = 0;
        for (long i = 5; n / i > 0; i *= 5) {
            zeros += n/i;
        }
        return zeros;
    }
};
// @lc code=end

