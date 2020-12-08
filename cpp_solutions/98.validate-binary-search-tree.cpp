/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    // BST, there's a case that when all subtrees are valid BST but not all the nodes' value on the 
    //      right subtree is smaller than root value. So, we need lower and upper bound to ensure that
    //      doesn't be judged as valid BST
    // Runtime: 20ms, beats 27.62%
    // Memory usage: 22.1MB, beats 29.51% 
    bool helper(TreeNode * root, long lower_bound, long upper_bound) {
        if (!root) {return true;}
        // The following two if statements are not necessary
        if (root -> left && root -> left -> val >= root -> val) {
            return false;
        }
        if (root -> right && root -> right -> val <= root -> val) {
            return false;
        }
        if (root -> val <= lower_bound || root -> val >= upper_bound) {
            return false;
        }
        if (!helper(root -> left, lower_bound, root -> val)) {return false;}
        if (!helper(root -> right, root -> val, upper_bound)) {return false;}
        return true;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end

