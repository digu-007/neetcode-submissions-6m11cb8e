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
    void dfs(TreeNode* root, int k, vector<int>& ans) {
        if (!root) return;
        dfs(root -> left, k, ans);
        if (ans.size() < k) ans.push_back(root -> val);
        dfs(root -> right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root, k, ans);
        return ans.back();
    }
};
