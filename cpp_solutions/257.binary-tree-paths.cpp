/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
using namespace std;

//Recursion:
class Solution {
public:
    //Pre-order tranversal
    vector<string> res;
    void paths(TreeNode* root, string s ){
        TreeNode * rr;
        rr = root;
        if( rr == NULL ){
            return ;
        }
        if( rr -> left == NULL && rr -> right == NULL ){
            s += to_string(rr -> val);
            res.push_back(s);
        }
        s += to_string(rr -> val);
        s += "->";
        if( rr -> left != NULL ){
            paths( rr-> left,s );
        }
        if( rr -> right != NULL ){
            paths( rr -> right, s );
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        //vector<string> res;
        TreeNode * rr;
        rr = root;
        string s = "";
        paths( root, s );
        return res;
    }
};

