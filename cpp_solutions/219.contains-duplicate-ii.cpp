/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    // Use a hash map to map an integer to a list of its index appeared in the nums
    // Runtime: 84ms, beats 21.18%
    // Memory usage: 23.7MB, beats 5.01%
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> nums_map;
        for (int i = 0; i < nums.size(); i ++) {
            nums_map[nums[i]].push_back(i);
        }
        for (auto v : nums_map) {
            for (int i = 0; i < v.second.size() - 1; i ++) {
                if (v.second[i + 1] - v.second[i] <= k) {return true;}
            }
        }
        return false;
    } 

    // This solution saves the vector space compared to solution 1, O(N)
    // Runtime: 52ms, beats 54.68%
    // Memory usage: 17.1MB, beats 39.84%
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums_map.count(nums[i]) == 0) {
                nums_map[nums[i]] = i;
            }
            else if (i - nums_map[nums[i]] <= k) {return true;}
            else {
                nums_map[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end

