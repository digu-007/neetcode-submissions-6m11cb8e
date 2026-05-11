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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode* node = head;
        while (node) {
            node = node -> next;
            ++total;
        }
        total -= n - 1;
        if (total == 1) return head -> next;
        node = head;
        while (total--) {
            if (total == 1) {
                node -> next = node -> next -> next;
                break;
            }
            node = node -> next;
        }
        return head;
    }
};
