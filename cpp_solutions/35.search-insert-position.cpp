/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    /*
    // This solution's runtime beats 92.34%, memory usage beats 29.03%
    int searchInsert(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0;
        int high = nums.size() - 1;
        if (target < nums[0]) return 0;
        if (target > nums[nums.size() - 1]) return nums.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        if (ans == -1) {
            for (int i = 0; i < nums.size() - 1; i ++) {
                if (nums[i] < target && nums[i + 1] > target) {
                    return i + 1;
                }
            }
        }
        return ans;
    }
    */

   int searchInsert(vector<int>& nums, int target) {
       int low = 0; 
       int high = nums.size() - 1;
       while (low <= high) {
           int mid = (low + high) / 2;
           if (nums[mid] == target) return mid;
           if (nums[mid] > target) high = mid - 1;
           else low = mid + 1;
       }
       return low;
   }
};
// @lc code=end

