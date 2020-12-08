/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int p1 = 0; 
        int p2 = height.size() - 1;
        while (p1 < p2) {
            if (height[p1] < height[p2]) {
                int area = (p2 - p1) * height[p1];
                p1 ++;
                if (area > max) {
                    max = area;
                }
            }
            else {
                int area = (p2 - p1) * height[p2];
                p2 --;
                if (area > max) {
                    max = area;
                }
            }
        }
        return max;
    }
};
// @lc code=end

