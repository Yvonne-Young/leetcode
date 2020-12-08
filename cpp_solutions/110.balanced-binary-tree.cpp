/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    // Runtime: 20ms, beats 49.18%
    // Memory usage: 22MB, beats 6.43%
    int Depth(TreeNode* root) {
        if (root == NULL) {return 0;}
        return max(Depth(root -> left), Depth(root -> right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {return true;}
        int left = Depth(root -> left);
        int right = Depth(root -> right);
        return abs(left - right) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
    }
};
// @lc code=end

