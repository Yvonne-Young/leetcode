/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    // Solution derived from 235. LCA of a Binary Search Tree
    // Case 1: 
    //      If p and q are in the left and right subtree of a node
    // Case 2: 
    //      If p or q is an ancestor of the other one
    // Runtime: 16ms, beats 91.46%
    // Memory usage: 14.7MB, beats 26.74%
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !q || !p) {return NULL;}
        if (root == p || root == q) {return root;}
        TreeNode * left = lowestCommonAncestor(root -> left, p, q);
        TreeNode * right = lowestCommonAncestor(root -> right, p, q);
        if (left && right) {return root;}
        return left ? left : right;
    }

    // Iterative soluton, keep tracking of path P and path Q
    // Runtime: 36ms, beats 11.42%
    // Memory usage: 17MB, beats 16.76%
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> temp(1, root);
        unordered_map<TreeNode *, TreeNode *> parent = {
            {root, NULL},
        };

        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode * current = temp.back();
            temp.pop_back();
            if (current -> left) {
                parent[current -> left] = current;
                temp.push_back(current -> left);
            }
            if (current -> right) {
                parent[current -> right] = current;
                temp.push_back(current -> right);
            }
        }

        vector<TreeNode *> path;
        while (p) {
            path.push_back(p);
            p = parent[p];
        }

        while (find(path.begin(), path.end(), q) == path.end()) {
            q = parent[q];
        }
        return q;
    }
};
// @lc code=end

