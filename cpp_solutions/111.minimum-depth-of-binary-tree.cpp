/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    // DFS Solution: 
    // Runtime: 12ms, beats 91.52%
    // Memory usage: 20.5MB, beats 5.38%
    int minDepth(TreeNode* root) {
        if (root == NULL) {return 0;}
        int level_left = 1;
        int level_right = 1;
        if (root -> left == NULL || root -> right == NULL) {
            return 1 + max(minDepth(root -> left), minDepth(root -> right));
        }
        level_left += minDepth(root -> left);
        level_right += minDepth(root -> right);
        return min(level_left, level_right);
    }
    
   // BFS Solution
   // Runtime: 16ms, beats 66.75%
   // Memory usage: 20MB, beats 81.62%
   int minDepth(TreeNode* root) {
       if (root == NULL) {return 0;}
       queue<TreeNode*> Q;
       Q.push(root);
       int level = 0;
       while (!Q.empty()) {
           level ++;
           int j = Q.size();
           for (int k = 0; k < j; k ++) {
               TreeNode* rt = Q.front();
               if (rt -> left) {Q.push(rt -> left);}
               if (rt -> right) {Q.push(rt -> right);}
               Q.pop();
               if (rt -> left == NULL && rt -> right == NULL) {
                   return level;
               }
           }
       }
       return -1;
   }
};
// @lc code=end

