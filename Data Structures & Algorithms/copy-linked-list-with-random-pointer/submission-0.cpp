/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* node = new Node(head -> val);
        mp[head] = node;
        node -> next = copyRandomList(head -> next);
        node -> random = mp[head -> random];
        return node;
    }
};
