class TrieNode {
public:
    TrieNode* children[26];
    bool is_word;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        is_word = false;
    }
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (auto &x: word) {
            if (!node -> children[x - 'a']) node -> children[x - 'a'] = new TrieNode();
            node = node -> children[x - 'a'];
        }
        node -> is_word = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (auto &x: word) {
            if (!node -> children[x - 'a']) return false;
            node = node -> children[x - 'a'];
        }
        return node -> is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (auto &x: prefix) {
            if (!node -> children[x - 'a']) return false;
            node = node -> children[x - 'a'];
        }
        return true;
    }
};
