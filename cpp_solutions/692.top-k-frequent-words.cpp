/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
public:
    // Runtime: 20ms, beats 81.32%
    // Memory usage: 13.2MB, beats 5.35%
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        std::map<string, int> mp;
        for (auto w: words) {
            mp[w] ++;
        }

        std::multimap<int, string> mp1;
        map<string, int>::reverse_iterator it0;
        for (it0 = mp.rbegin(); it0 != mp.rend(); it0 ++) {
            mp1.insert({it0 -> second, it0 -> first});
        }

        int i = 0;
        map<int, string>::reverse_iterator it;
        for (it = mp1.rbegin(); it != mp1.rend(); it ++) {
            if (i < k) {
                ans.push_back(it -> second);
            }
            i ++;
        }

        return ans;
    }
};
// @lc code=end

