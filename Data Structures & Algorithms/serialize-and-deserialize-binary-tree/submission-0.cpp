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

class Codec {
public:
    void dfs(TreeNode* root, string& ans) {
        if (!root) {
            ans += "N,";
            return;
        }
        ans += to_string(root -> val) + ",";
        dfs(root -> left, ans);
        dfs(root -> right, ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        dfs(root, ans);
        return ans;
    }

    TreeNode* decode(vector<int>& a, int& i) {
        if (a[i] == 1111) {
            ++i;
            return nullptr;
        }
        TreeNode* root = new TreeNode(a[i++]);
        root -> left = decode(a, i);
        root -> right = decode(a, i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> a;
        for (int i = 0; i < data.size(); ++i) {
            string cur = "";
            bool n = false;
            while (i < data.size() and data[i] != ',') {
                if (data[i] == 'N') {
                    n = true;
                    ++i;
                    break;
                } else {
                    cur += data[i++];
                }
            }
            if (n) {
                a.emplace_back(1111);
            } else {
                a.emplace_back(stoi(cur));
            }
        }
        int i = 0;
        return decode(a, i);
    }
};
