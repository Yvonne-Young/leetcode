/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
// Runtime: 4ms, beats 48.79%
// Memory usage: 9MB, beats 9.57%
private: 
    vector<int> tree_list;
public:
    void DFS(TreeNode* root) {
        if (root == NULL) {return;}        
        if (root -> left != NULL) {
            DFS(root -> left);
        }
        if (root -> right != NULL) {
            DFS(root -> right);
        }
        tree_list.push_back(root -> val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        DFS(root);
        return tree_list;
    }
};
// @lc code=end

