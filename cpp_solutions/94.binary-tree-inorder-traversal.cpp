/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    // DFS, recursive
    // Runtime: 4ms, beats 49.96%
    // Memory usage: 9MB, beats 10.86%
    void DFS_helper(TreeNode* root, vector<int>& traversal) {
        if (!root) {return;}
        else {
            if (root -> left) {DFS_helper(root -> left, traversal);}
            traversal.push_back(root -> val);
            if (root -> right) {DFS_helper(root -> right, traversal);}
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        DFS_helper(root, traversal);
        return traversal;
    }
};
// @lc code=end

