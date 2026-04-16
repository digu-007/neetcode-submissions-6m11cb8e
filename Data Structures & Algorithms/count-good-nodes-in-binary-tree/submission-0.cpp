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
    int dfs(TreeNode* root, int cur) {
        if (!root) return 0;
        int ans = 0;
        if (root -> val >= cur) {
            cur = root -> val;
            ++ans;
        }
        ans += dfs(root -> left, cur) + dfs(root -> right, cur);
        return ans;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, -111);
    }
};
