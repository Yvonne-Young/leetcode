/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                int sum = nums[i] + nums[front] + nums[back];
                if (abs(sum - target) <= abs(closest)) {
                    closest = sum - target;
                }
                if (sum < target) {front ++;}
                else if (sum > target) {back --;}
                else {return target;}
            }
        }
        return (closest + target);
    }
};
// @lc code=end

