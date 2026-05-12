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
    int idx = 0;
    unordered_map<int, int> mp;

    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;
        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        int mid = mp[val];
        root -> left = dfs(preorder, l, mid - 1);
        root -> right = dfs(preorder, mid + 1, r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        return dfs(preorder, 0, preorder.size() - 1);
    }
};
