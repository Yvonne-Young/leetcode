/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    // Runtime: 12ms, beats 90.1%
    // Memory usage: 21.5MB, beats 38.79%
    // DFS, recursion
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {return false;}
        if (root->left == NULL && root->right == NULL && root->val == sum) {return true;}
        if (root->left != NULL || root->right != NULL) {
            return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
        }
        return false;
    }
};
// @lc code=end

