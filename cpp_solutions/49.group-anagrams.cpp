/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    // Brute force solution
    // test cases all passed but time limit exceeded
    /*
    bool isAnagram(string s1, string s2) {
        if (s1.length() != s2.length()) {return false;}
        std::unordered_map<char, int> char_map1, char_map2;
        for (auto s: s1) {
            char_map1[s] ++;
        }
        for (auto s: s2) {
            char_map2[s] ++;
        }
        if (char_map1 == char_map2) {return true;}
        else {return false;}
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.size() == 1) {
            res.push_back({strs[0]});
            return res;
        }
        vector<string> group;
        group.push_back(strs[0]);
        res.push_back(group);
        bool flag = false;
        for (int i = 1; i < strs.size(); i ++) {
            for (int j = 0; j < res.size(); j ++) {
                if (isAnagram(strs[i], res[j][0])) {
                    res[j].push_back(strs[i]);
                    flag = true;
                }
            }
            if (flag == false) {
                res.push_back({strs[i]});
            }
            flag = false;
        }
        return res;
    }
    */

   // Sort each string and if two sorted strings are the same, then they are anagrams
   // Use unordered_map to store groups of anagrams
   // Runtime: 64ms, beats 67.86%
   // Memory usage: 21.1MB, beats 5.15%
   vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> res;
       std::unordered_map<string, vector<string>> umap;
       for (auto s: strs) {
           string t = s;
           sort(t.begin(), t.end());
           umap[t].push_back(s);
       }
       for (auto m: umap) {
           res.push_back(m.second);
       }
       return res;
   }
};
// @lc code=end

