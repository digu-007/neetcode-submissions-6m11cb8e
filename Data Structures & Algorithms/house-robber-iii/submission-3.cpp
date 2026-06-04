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
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }

    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        pair<int, int> l = dfs(root -> left), r = dfs(root -> right);
        int robbed = root -> val + l.second + r.second;
        int not_robbed = max(l.first, l.second) + max(r.first, r.second);
        return {robbed, not_robbed};
    }
};