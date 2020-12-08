/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    // Level Order Traversal but differentiate the level is odd or even
    // If level is odd, then from left -> right
    // If level is even, then from right -> left (here need to insert the nodes at the begin of tmp)
    // Runtime: 4ms, beats 74.04%
    // Memory usage: 12.6MB, beats 44.88%
    // This can use a deque instead of a vector to achieve more efficient insertion at the begining
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {return ans;}
        queue<TreeNode *> q;
        q.push(root);
        ans.push_back({root -> val});
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            cout << level;
            vector<int> tmp;
            for (int i = 0; i < n; i ++) {
                TreeNode * p = q.front();
                q.pop();
                if (level % 2 == 1) {
                    if (p -> left) {
                        tmp.push_back(p -> left -> val);
                        q.push(p -> left);
                    }
                    if (p -> right) {
                        tmp.push_back(p -> right -> val);
                        q.push(p -> right);
                    }
                }
                else {
                    vector<int> ttmp;
                    if (p -> left) {
                        q.push(p -> left);
                    }
                    if (p -> right) {
                        q.push(p -> right);
                    }
                    if (p -> right) {
                        ttmp.push_back(p -> right -> val);
                    }
                    if (p -> left) {
                        ttmp.push_back(p -> left -> val);
                    }
                    tmp.insert(tmp.begin(), ttmp.begin(), ttmp.end());
                }
            }
            if (tmp.size() > 0) {ans.push_back(tmp);}
            level++;
        } 
        return ans;
    }
};
// @lc code=end

