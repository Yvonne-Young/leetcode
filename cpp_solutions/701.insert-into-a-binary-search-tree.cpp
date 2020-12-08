/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    // Iterative, DFS, O(logN) 
    // Runtime: 120ms, beats 57.64%
    // Memory usage: 60.1MB, beats 49.92%
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {return new TreeNode(5);}
        TreeNode * current = root;
        while (true) {
            if (val > current -> val) {
                if (current -> right) {
                    current = current -> right;
                }
                else {
                    current -> right = new TreeNode(val);
                    break;
                }
            }
            if (val < current -> val) {
                if (current -> left) {
                    current = current -> left;
                }
                else {
                    current -> left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
// @lc code=end

