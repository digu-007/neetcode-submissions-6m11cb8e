/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        // 2 4 6 8 10
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while (fast and fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* s = slow -> next;
        slow -> next = nullptr;
        ListNode* rev = nullptr;
        while (s) {
            ListNode* nxt = s -> next;
            s -> next = rev;
            rev = s;
            s = nxt;
        }
        ListNode* f = head;
        s = rev;
        while (s) {
            ListNode* tempf = f -> next;
            ListNode* temps = s -> next;
            f -> next = s;
            s -> next = tempf;
            f = tempf;
            s = temps;
        }
    }
};
