/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    // Runtime: 28ms, beats 5.86%
    // Memory usage: 10.4MB, beats 78.56%
    /*
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int p1 = 0; 
        int p2 = 0;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] < nums2[p2]) {
                p1 ++;
            }
            else if (nums1[p1] > nums2[p2]) {
                p2 ++;
            }
            else {
                if (find(res.begin(), res.end(), nums1[p1]) == res.end()){
                    res.push_back(nums1[p1]);
                }
                p1 ++; 
                p2 ++;
            }
        }
        return res;
    }
    */

    // Runtime: 32ms, beats 5.86%
    // Memory usage: 10.5MB, beats 78.56%
    /*
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.size() <= nums2.size()) {
            for (int i = 0; i < nums1.size(); i ++) {
                if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end() &&
                    find(ans.begin(), ans.end(), nums1[i]) == ans.end()) {
                        ans.push_back(nums1[i]);
                }
            }
        }
        else {
            for (int i = 0; i < nums2.size(); i ++) {
                if (find(nums1.begin(), nums1.end(), nums2[i]) != nums1.end() &&
                    find(ans.begin(), ans.end(), nums2[i]) == ans.end()) {
                        ans.push_back(nums2[i]);
                }
            }
        }
        return ans;
    }
    */

    // Runtime: 12ms, beats 62.59%
    // Memory usage: 10.9MB, beats 78.56%
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto n : nums2) {
            if (m.count(n) != 0) {
                ans.push_back(n);
                m.erase(n);
            }
        }
        return ans;
    }
};
// @lc code=end

