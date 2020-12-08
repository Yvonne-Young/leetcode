/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    // Runtime: 40ms, beats 89.4%
    // Memory usage: 20MB, beats 6.63%
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int i : nums) {
            umap[i] ++;
        }
        for (auto i : umap) {
            if (i.second > nums.size() / 2) {return i.first;}
        }
        return -1;
    }
};
// @lc code=end

