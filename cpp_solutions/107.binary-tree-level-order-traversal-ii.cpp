/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    // get the depth of the tree
    int height(TreeNode* node) {
        if (node == NULL) {return 0;}
        else {
            int lheight = height(node -> left);
            int rheight = height(node -> right);
            if (lheight > rheight) {
                return (lheight + 1);
            }
            else {
                return (rheight + 1);
            }
        }
    }

    // level order push back
    void levelOrder(vector<vector<int>>& ans, TreeNode* node, int level) {
        if (node == NULL) {return;}
        ans[level].push_back(node -> val);
        levelOrder(ans, node -> left, level - 1);
        levelOrder(ans, node -> right, level - 1);
    }

    // Runtime: 4ms, beats 91.88%
    // Memory usage: 13.4MB, beats 19.04%
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans(h, vector<int> {});
        levelOrder(ans, root, h - 1);
        return ans;
    }

    // Level Order Traversal and reverse the list
    // Runtime: 0ms, beats 100%
    // Memory usage: 13.2MB, beats 30.44%
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {return ans;}
        queue<TreeNode *> q;
        q.push(root);
        ans.push_back({root -> val});
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; i ++) {
                TreeNode* p = q.front();
                q.pop();
                if (p -> left != NULL) {
                    q.push(p -> left);
                    tmp.push_back(p -> left -> val);
                }
                if (p -> right != NULL) {
                    q.push(p -> right);
                    tmp.push_back(p -> right -> val);
                }
            }
            if (tmp.size() != 0) {ans.push_back(tmp);}
        } 
        vector<vector<int>> ans2;
        for (int i = ans.size() - 1; i >= 0; i --) {
            ans2.push_back(ans[i]);
        }
        return ans2;
    }
};
// @lc code=end

