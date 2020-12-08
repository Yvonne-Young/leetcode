/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0; 
        int end = s.length() - 1;
        while (front < end) {
            if (isalnum(s[front]) == false) {
                front ++;
                continue;
            }
            if (isalnum(s[end]) == false) {
                end --;
                continue;
            }
            if (toupper(s[front]) != toupper(s[end])) {return false;}
            front ++;
            end --;      
        }
        return true;
    }
};
// @lc code=end

