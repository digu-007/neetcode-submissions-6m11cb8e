class TrieNode {
public:
    vector<TrieNode*> child;
    bool is_word;

    TrieNode() {
        child.resize(26, nullptr);
        is_word = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (auto &x: word) {
            if (!cur -> child[x - 'a']) {
                cur -> child[x - 'a'] = new TrieNode();
            }
            cur = cur -> child[x - 'a'];
        }
        cur -> is_word = true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }

    bool search(string& word, int idx, TrieNode* cur) {
        TrieNode* next = cur;
        for (int i = idx; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (cur -> child[j] and search(word, i + 1, cur -> child[j])) return true;
                }
                return false;
            } else {
                if (!cur -> child[word[i] - 'a']) return false;
                cur = cur -> child[word[i] - 'a'];
            }
        }
        return cur -> is_word;
    }
};
