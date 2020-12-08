/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    // DFS search, O(logN)
    // Runtime: 12ms, beats 64.03%
    // Memory usage: 19.4MB, beats 64.04%
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == NULL) {
            return depth;
        }
        int d1 = maxDepth(root -> left);
        int d2 = maxDepth(root -> right);
        depth = max(d1, d2) + 1;
        return depth;
    }

    // BFS search, O(logN)
    // Runtime: 16ms, beats 27.87%
    // Memory usage: 19.2MB, beats 78.24%
    int maxDepth(TreeNode* root) {
        if (root == NULL) {return 0;}
        int ans = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            ans ++;
            int n = q.size();
            for (int i = 0; i < n; i ++) {
                TreeNode* p = q.front();
                q.pop();
                if (p -> left != NULL) {
                    q.push(p -> left);
                }
                if (p -> right != NULL) {
                    q.push(p -> right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

