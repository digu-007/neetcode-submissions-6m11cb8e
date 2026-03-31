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
    int dfs(TreeNode* cur) {
        int depth = 1;
        if (cur -> left != nullptr) {
            depth = 1 + dfs(cur -> left);
        }
        if (cur -> right != nullptr) {
            depth = max(depth, 1 + dfs(cur -> right));
        }
        return depth;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return dfs(root);
    }
};
