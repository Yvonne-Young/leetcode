/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    // Baseline: sort the array and find the successive int with same value
    // Runtime: 20ms, beats 45.86%, O(NlogN)
    // Memory Usage: 11.4MB, beats 19.08%
    // This solution modifies the array
    /*
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i ++) {
            if (nums[i] == nums[i + 1]) {return nums[i];}
        }
        return 0;
    }
    */

    // Solution2: keep an extra array to check if nums[i] has already been pushed into it
    // Runtime: 1736ms, beats 5.54%
    // Memory usage: 11.6MB, beats 19.08%
    // This solution doesn't modify the array
    /*
    int findDuplicate(vector<int>& nums) {
        vector<int> tmp;
        for (int i = 0; i < nums.size(); i ++) {
            if (find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()) {return nums[i];}
            tmp.push_back(nums[i]);
        }
        return 0;
    }
    */

    // Solution3: Cycling list, Tortoise and hare problem
    // Runtime: 12ms, beats 93.51%
    // Memory usage: 11.5MB, beats 19.08%
    // This solution meets all the requirements
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];
        int tortoise = nums[0];
        do {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        } while (hare != tortoise);

        tortoise = nums[0];
        while (hare != tortoise) {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        return hare;
    }
};
// @lc code=end

