class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node (int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    Node* l;
    Node* r;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        l = new Node(0, 0);
        r = new Node(0, 0);
        l -> next = r;
        r -> prev = l;
    }
    
    void insert(Node* node) {
        Node* mru = r -> prev;
        mru -> next = node;
        r -> prev = node;
        node -> next = r;
        node -> prev = mru;
    }

    void remove(Node* node) {
        Node* front = node -> next;
        Node* back = node -> prev;
        back -> next = front;
        front -> prev = back;
    }

    int get(int key) {
        if (mp.count(key)) {
            Node* node = mp[key];
            remove(node);
            insert(node);
            return mp[key] -> val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) remove(mp[key]);
        Node* node = new Node(key, value);
        insert(node);
        mp[key] = node;
        if (mp.size() > cap) {
            Node* lru = l -> next;
            remove(lru);
            mp.erase(lru -> key);
            delete lru;
        }
    }
};
