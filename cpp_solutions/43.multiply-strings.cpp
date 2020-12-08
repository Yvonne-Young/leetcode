/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include <math.h>

class Solution {
public:
    /*
    // This solution has integer overflow problem
    // Time limit exceeds on certain cases
    unordered_map<char, int> s2i_map = {
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

    unordered_map<int, char> i2s_map = {
        {0, '0'},
        {1, '1'},
        {2, '2'},
        {3, '3'},
        {4, '4'},
        {5, '5'},
        {6, '6'},
        {7, '7'},
        {8, '8'},
        {9, '9'}
    };

    int str2int(string num) {
        int res = 0;
        int n = num.length();
        for (int i = n - 1; i >= 0; i --) {
            res += (s2i_map[num[i]] * pow(10, n - i - 1));
        }
        return res;
    }

    string int2str(int num) {
        string res = "";
        if (num == 0) {return "0";}
        while (num != 0) {
            res = i2s_map[num % 10] + res;
            num /= 10;
        }
        return res;
    }

    string multiply(string num1, string num2) {
        int n1 = str2int(num1);
        int n2 = str2int(num2);
        long r  = n1 * n2;
        string res = int2str(r);
        return res;
    }
    */

    // This solution uses hand multiplication
    // Runtime: 4ms, beats 96.26%
    // Memory usage: 7.1MB, beats 5.27%
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {return "0";}
        int m = num1.size(); 
        int n = num2.size();
        vector<int> tmp(n + m, 0);
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                tmp[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                tmp[i + j] += tmp[i + j + 1] / 10;
                tmp[i + j + 1] %= 10;
            }
        }
        int i = 0;
        while (i < n + m && tmp[i] == 0) {
            i ++;
        }
        string res = "";
        while (i < n + m) {
            res += (tmp[i] + '0');
            i ++;
        }
        return res;
    }
};
// @lc code=end