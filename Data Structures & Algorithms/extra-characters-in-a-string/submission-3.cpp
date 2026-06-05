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
        for (int i = l; i < a.size(); ++i) {
            if (!cur -> child[a[i] - 'a']) return;
            cur = cur -> child[a[i] - 'a']; 
            if (cur -> is_word) dp[l] = min(dp[l], dp[i + 1]);
        }
        return;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        Trie trie(n + 1);
        for (auto &x: dictionary) {
            trie.add(x);
        }
        trie.dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            trie.dp[i] = min(trie.dp[i], trie.dp[i + 1] + 1);
            trie.match(i, s);
            cout << trie.dp[i] << " ";
        }
        return trie.dp[0];
    }
};