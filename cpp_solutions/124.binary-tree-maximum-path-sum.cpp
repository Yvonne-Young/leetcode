/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    // Runtime: 40ms, beats 48.56%
    // Memory usage: 29.1MB, beats 88.32%
    int DFS(TreeNode* root, int& max_sum) {
        if (root == NULL) {return 0;}
        int left = max(0, DFS(root -> left, max_sum));
        int right = max(0, DFS(root -> right, max_sum));
        int tmp = max(root -> val, root -> val + max(left, right));
        max_sum = max(max_sum, max(tmp, root -> val + left + right));
        return tmp;
    }

    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        DFS(root, max_sum);       
        return max_sum; 
    }
};
// @lc code=end

