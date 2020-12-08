/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    template<typename T>
    vector<T> slice(vector<T> & v, int m, int n) {
        vector<T> vec(n - m + 1);
        std::copy(v.begin() + m, v.begin() + n + 1, vec.begin());
        return vec;
    }

    // This solution uses the backtracking without memoization. 
    // exceeds time limits when testcases are large
    // Algorithm is correct
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] >= n - 1) {return true;}
        if (nums[0] == 0) {return false;}
        bool flag = true;
        for (int i = 0; i < n; i ++) {
            if (nums[i] != 1) {flag = false;}
        }
        if (flag) {return true;}
        for (int i = 1; i <= nums[0]; i ++) {
            vector<int> sub_arr(n - i);
            std::copy(nums.begin() + i, nums.begin() + n, sub_arr.begin());
            if (canJump(sub_arr)) {return true;}
        }
        return false;
    }

    // DP from top to bottom, O(N^2) 
    // Runtime: 20ms, beats 47.73%
    // Memory usage: 13.2MB, beats 47.68%
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> state(n, false);
        state[0] = true;
        bool flag = true;
        for (int i = 0; i < n; i ++) {
            if (nums[i] != 1) {
                flag = false;
            }
        }
        if (flag) {return true;}
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (state[j] && nums[j] + j >= i) {
                    state[i] = true;
                    break;
                }
            }
        }
        return state[n - 1];
    }

    // Greedy algorithm, keep track of the left most good index
    // A good index means I can jump from it to the end
    // Runtime: 16ms, beats 87.42%
    // Memory usage: 13.2MB, beats 16.29%
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastGood = n - 1;
        for (int i = n - 1; i >= 0; i --) {
            if (nums[i] + i >= lastGood) {
                lastGood = i;
            }
        }
        return lastGood == 0;
    }
};
// @lc code=end

