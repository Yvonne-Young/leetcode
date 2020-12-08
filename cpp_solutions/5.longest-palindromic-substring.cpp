/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    /*
    // This solution is not 100% passed the test
    bool isPalindrome(string s) {
        // This function is to check if a string is Palindrome
        int front = 0;
        int end = s.length() - 1;
        while (front < end) {
            if (isalnum(s[front]) == false) {
                front ++;
            }
            if (isalnum(s[end]) == false) {
                end --;
            }
            if (s[front] != s[end]) {return false;}
            front ++;
            end --;
        }
        return true;
    }

    vector<string> FindAllSubstring(string s, char c) {
        // Find all the location of one character in the string
        vector<size_t> positions;
        vector<string> sub;
        size_t pos = s.find(c);
        size_t pos_tmp = s.find(c);
        while (pos_tmp != string::npos) {
            pos_tmp = s.find(c, pos_tmp + 1);
            sub.push_back(s.substr(pos, pos_tmp - pos + 1));
        }
        return sub;
    }

    string longestPalindrome(string s) {
        vector<string> substrings;
        if (s.length() == 1) {return s;}
        string longest = s.substr(0, 1);
        for (int i = 0; i < s.length(); i ++) {
            vector<string> sub = FindAllSubstring(s, s[i]);
            substrings.insert(substrings.end(), sub.begin(), sub.end());
        }

        for (string str : substrings) {
            if (isPalindrome(str)) {
                if (str.size() > longest.size()) {
                    longest = str;
                }
            }
        }
        return longest;
    }
    */

   // dynamic programming solution
   string longestPalindrome(string s) {
       string longest = "";
       int n = s.length();
       if (n == 0) {return "";}
       longest += s[0];
       if (n == 1) {return longest;}
       vector<vector<bool>> dp(n, vector<bool>(n, false));
       // s[i][i] is definitely a Palindrome
       for (int i = 0; i < s.length(); i ++) {
           dp[i][i] = true;
       }
       for (int i = n - 1; i >= 0; i --) {
           for (int j = i + 1; j < n; j ++) {
               if (s[i] == s[j]) {
                    if (j - i == 1 || dp[i + 1][j - 1] == true) {
                        dp[i][j] = true;
                        if (j - i + 1 > longest.length()) {
                            longest = s.substr(i, j - i + 1);
                        }
                    }
               }
           }
       }
       return longest;
   }
};
// @lc code=end

