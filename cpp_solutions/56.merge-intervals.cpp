/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    // Runtime: 60ms, beats 25.65%
    // Memory usage: 14.7MB, beats 13.43%
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) {return intervals;}
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged_intervals;
        merged_intervals.push_back(intervals[0]);
        // sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2){ return v1[0] < v2[0]; });
        for (int i = 1; i < n; i ++) {
            if (merged_intervals.back()[1] >= intervals[i][0]) {
                merged_intervals.back()[1] = max(merged_intervals.back()[1], intervals[i][1]);
            }
            else {
                merged_intervals.push_back(intervals[i]);
            }
        }
        return merged_intervals;
    }
};
// @lc code=end

