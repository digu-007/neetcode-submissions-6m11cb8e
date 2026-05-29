/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> vis;
        return dfs(node, vis);
    }

    Node* dfs(Node* node, map<Node*, Node*>& vis) {
        if (!node) return nullptr;
        if (vis.count(node)) return vis[node];
        Node* ans = new Node(node -> val);
        vis[node] = ans;
        for (auto &x: node -> neighbors) {
            ans -> neighbors.push_back(dfs(x, vis));
        }
        
        return ans;
    }
};
