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
    bool dfs(TreeNode* root, int lo, int hi) {
        if (!root) return true;
        if ((root -> val >= hi) or (root -> val <= lo)) return false;
        return (dfs(root -> left, lo, root -> val) & dfs(root -> right, root -> val, hi));
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, -1111, 1111);
    }
};
