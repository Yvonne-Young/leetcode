/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
// Runtime: 64ms, beats 76.78%
// Memory usage: 29.4MB, beats 16.47%
private: 
    vector<int> tree_list;
    int index = -1;
public:
     void DFS(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root -> left != NULL) {
            DFS(root -> left);
        }
        tree_list.push_back(root -> val);
        if (root -> right != NULL) {
            DFS(root -> right);
        }
    }

    BSTIterator(TreeNode* root) {
        vector<int> tree_list;
        DFS(root);
    }
    
    /** @return the next smallest number */
    int next() {
        index ++;
        return tree_list[index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (index + 1 < tree_list.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

