/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Case 1: 
    //      p in the left subtree and q in the right subtree and vice sersa
    // Case 2: 
    //      p is an ancestor of q
    // Case 3: 
    //      q is an ancestor os p
    // If they are both in the left subtree: search on the left subtree
    // If they are both in the right subtree: search on the right subtree
    // Runtime: 40ms, beats 25.02%
    // Memory usage: 23.9MB, beats 14.92%
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p -> val;
        int qVal = q -> val;
        if (root -> val > pVal && root -> val > qVal) {
            // both p and q are in the left subtree
            return lowestCommonAncestor(root -> left, p, q);
        }
        if (root -> val < pVal && root -> val < qVal) {
            // both p and q are in the right subtree
            return lowestCommonAncestor(root -> right, p, q);
        }
        else {
            return root;
        }
    }

    // Iterative version of the above solution
    // Runtime: 32ms, beats 76.18%
    // Memory usage: 23.9MB, beats 14.92%
    // This is faster because calling the recursive function is slow
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p -> val;
        int qVal = q -> val;
        while (root != NULL) {
            if (root -> val > qVal && root -> val > pVal) {
                root = root -> left;
            }
            else if (root -> val < qVal && root -> val < pVal) {
                root = root -> right;
            }
            else {return root;}
        }
        return NULL;
    }
};
// @lc code=end

