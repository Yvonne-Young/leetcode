/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    // Runtime: 40ms, beats 35.34%
    // Memory usage: 12MB, beats 5.68%
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort intervals
        if (intervals.size() == 0) {return 0;}
        vector<vector<int>> tmp;
        vector<vector<int>> remove_list;
        sort(intervals.begin(), intervals.end());
        tmp.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i][0] < tmp.back()[1]) {
                // overlap happens 
                tmp.back()[1] = min(intervals[i][1], tmp.back()[1]);
                remove_list.push_back(intervals[i][1] > tmp.back()[1] ? intervals[i] : tmp.back());
            }
            else {
                tmp.push_back(intervals[i]);
            }
        }
        return remove_list.size();
    }
};
// @lc code=end

