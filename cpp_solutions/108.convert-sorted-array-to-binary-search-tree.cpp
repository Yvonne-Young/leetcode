/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Runtime: 32ms, beats 28.55%
    // Memory usage: 30.7MB, beats 13.46%
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {return NULL;}
        if (nums.size() == 1) {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }
        int mid = (nums.size() - 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root -> left = sortedArrayToBST(left);
        root -> right = sortedArrayToBST(right);

        return root;
    }
};
// @lc code=end

