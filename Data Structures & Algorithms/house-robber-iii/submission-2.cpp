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
    map<pair<TreeNode*, bool>, int> dp;

    int rob(TreeNode* root) {
        return max(dfs(root, false), dfs(root, true));
    }

    int dfs(TreeNode* root, bool robbed) {
        if (!root) return 0;
        if (dp.count({root, robbed})) return dp[{root, robbed}];
        int l = dfs(root -> left, !robbed);
        int r = dfs(root -> right, !robbed);
        dp[{root, robbed}] = 0;
        if (!robbed) {
            int ll = dfs(root -> left, robbed);
            int rr = dfs(root -> right, robbed);
            dp[{root, robbed}] = max(max(l + r, l + rr), max(ll + r, ll + rr));
        } else {
            dp[{root, robbed}] = root -> val + l + r;
        }
        return dp[{root, robbed}];
    }
};