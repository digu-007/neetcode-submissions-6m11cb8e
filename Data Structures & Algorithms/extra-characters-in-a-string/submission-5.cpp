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
    vector<int> dp;

    Trie(int n) {
        root = new TrieNode();
        dp.resize(n, 50);
    }

    void add(string s) {
        TrieNode* cur = root;
        for (auto &x: s) {
            if (!cur -> child[x - 'a']) cur -> child[x - 'a'] = new TrieNode();
            cur = cur -> child[x - 'a'];
        }
        cur -> is_word = true;
    }

    void match(int l, string& a) {
        TrieNode* cur = root;
        for (int i = l; i <= a.size(); ++i) {
            if (!cur -> child[a[i - 1] - 'a']) return;
            cur = cur -> child[a[i - 1] - 'a']; 
            if (cur -> is_word) dp[i] = min(dp[l - 1], dp[i]);
        }
        return;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size(), m = dictionary.size();
        Trie trie(n + 1);
        for (auto &x: dictionary) {
            trie.add(x);
        }
        trie.dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            trie.dp[i] = min(trie.dp[i], trie.dp[i - 1] + 1);
            trie.match(i, s);
        }
        return trie.dp[n];
    }
};