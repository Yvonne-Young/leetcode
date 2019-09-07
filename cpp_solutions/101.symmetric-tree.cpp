/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Recursive:
class Solution {
public:
    bool isMirror( TreeNode* r1, TreeNode* r2 ){
        if ( r1 == NULL && r2 == NULL ){
            return true;
        }
        if ( r1 == NULL || r2 == NULL ){
            return false;
        }
        if ( r1 -> val == r2 -> val ){
            return ( isMirror ( r1 -> left, r2 -> right ) && isMirror( r1 -> right, r2 -> left ) );
        }
        else{
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror( root, root );
    }
};

