class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char &x: word) {
            if (!node -> children.count(x)) {
                node -> children[x] = new TrieNode();
            }
            node = node -> children[x];
        }
        node -> is_word = true;
    }

    void search(string& s, vector<bool>& dp, int l, int r) {
        TrieNode* node = root;
        for (int i = l; i <= r; ++i) {
            cout << s[i] << "\n";
            if (!node -> children.count(s[i])) break;
            cout << node -> is_word << " " << dp[i + 1] << "\n";
            node = node -> children[s[i]];
            if (node -> is_word and dp[i + 1]) {
                dp[l] = true;
                break;
            }
        }
    }
};

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), mx = 0;
        Trie trie;
        for (auto &x: wordDict) {
            mx = max(mx, int(x.size()));
            trie.insert(x);
        }
        vector<bool> dp(n + 1);
        dp[n] = true;
        for (int i = n - 1; i >= 0; --i) {
            trie.search(s, dp, i, min(n - 1, i + mx));
            cout << dp[i] << "\n";
        }
        return dp[0];
    }
};
