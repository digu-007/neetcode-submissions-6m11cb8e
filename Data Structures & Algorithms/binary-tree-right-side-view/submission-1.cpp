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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int len = q.size(), cur = 111;
            for (int i = 0; i < len; ++i) {
                TreeNode* f = q.front();
                q.pop();
                if (f) {
                    cur = f -> val;
                    q.push(f -> left);
                    q.push(f -> right);
                }
            }
            if (cur != 111) ans.push_back(cur);
        }
        return ans;
    }
};
