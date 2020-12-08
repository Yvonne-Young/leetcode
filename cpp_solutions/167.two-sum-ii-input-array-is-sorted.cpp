/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    // Two pointers
    // Runtime: 4ms, beats 99.82%
    // Memory usage: 10MB, beats 99.93%
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0;
        int p2 = numbers.size() - 1;
        vector<int> ans;
        while (p1 != p2) {
            if (numbers[p1] + numbers[p2] == target) {
                ans.push_back(p1 + 1);
                ans.push_back(p2 + 1);
                return ans;
            }
            if (numbers[p1] + numbers[p2] < target) {
                p1 ++;
                continue;
            }
            else {
                p2 --;
            }
        }
        return ans;
    }
};
// @lc code=end

