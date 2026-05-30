class TrieNode {
public:
    vector<TrieNode*> child;
    bool is_word;

    TrieNode() {
        child.resize(26, nullptr);
        is_word = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void add(string s) {
        TrieNode* cur = root;
        for (auto &x: s) {
            if (!cur -> child[x - 'a']) cur -> child[x - 'a'] = new TrieNode();
            cur = cur -> child[x - 'a'];
        }
        cur -> is_word = true;
    }
};

class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;
    unordered_set<string> ans;

    void dfs(int i, int j, TrieNode* cur, vector<vector<char>>& board, string& word) {
        if (i < 0 or j < 0 or i >= n or j >= m or vis[i][j] or !cur -> child[board[i][j] - 'a']) return;
        vis[i][j] = true;
        cur = cur -> child[board[i][j] - 'a'];
        word += board[i][j];
        if (cur -> is_word) ans.insert(word);
        dfs(i + 1, j, cur, board, word);
        dfs(i - 1, j, cur, board, word);
        dfs(i, j - 1, cur, board, word);
        dfs(i, j + 1, cur, board, word);
        word.pop_back();
        vis[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (auto &x: words) {
            trie.add(x);
        }
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                TrieNode* cur = trie.root;
                string temp = "";
                dfs(i, j, cur, board, temp);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
