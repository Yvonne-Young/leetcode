/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            int front = i + 1;
            int end = nums.size() - 1;
            while (front < end) {
                if (nums[i] + nums[front] + nums[end] < 0) {
                    front ++;
                }
                else if (nums[i] + nums[front] + nums[end] > 0) {
                    end --;
                }
                else {
                    vector<int> sol(3, 0);
                    sol[0] = nums[i];
                    sol[1] = nums[front];
                    sol[2] = nums[end];
                    res.push_back(sol);
                    while ((front < end) && (sol[1] == nums[front])) {
                        front ++;
                    }
                    while ((front < end) && (sol[2] == nums[end])) {
                        end --;
                    }
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    i ++;
            }
        }
        return res;
    }
};
// @lc code=end

