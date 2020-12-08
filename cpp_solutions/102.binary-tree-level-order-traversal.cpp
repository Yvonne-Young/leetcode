/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    // BFS, based on the template of the BFS
    // Runtime: 4ms, beats 80.83%
    // Memory usage: 13MB, beats 34.33%
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> tree_q;
        if (root == NULL) {return ans;}
        tree_q.push(root);
        ans.push_back({root -> val});
        while (!tree_q.empty()) {
            vector<int> level;
            int n = tree_q.size();
            for (int i = 0; i < n; i ++) {
                TreeNode * tmp = tree_q.front();
                tree_q.pop();
                if (tmp -> left != NULL) {
                    tree_q.push(tmp -> left);
                    level.push_back(tmp -> left -> val);
                }
                if (tmp -> right != NULL) {
                    tree_q.push(tmp -> right);
                    level.push_back(tmp -> right -> val);
                }
            }
            if (level.size() != 0) {ans.push_back(level);}
        }

        return ans;
    }
};
// @lc code=end

