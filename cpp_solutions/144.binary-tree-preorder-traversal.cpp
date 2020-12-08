/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    // DFS, recursive, pre-order: root , root -> left , root -> right
    // Runtime: 4ms, beats 49.41%
    // Memory usage: 8.9MB, beats 5.41%
    void DFS_helper(TreeNode* root, vector<int>& traversal) {
        if (!root) {return;}
        else {traversal.push_back(root -> val);}
        if (root -> left) {DFS_helper(root -> left, traversal);}
        if (root -> right) {DFS_helper(root -> right, traversal);}
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        DFS_helper(root, traversal);
        return traversal;
    }
};
// @lc code=end

