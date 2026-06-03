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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = new ListNode(0);
        ListNode* dummy = ans;
        ListNode* original = head;
        while (head) {
            int sz = 0;
            ListNode* rev = nullptr;
            ListNode* check = head;
            while (check and sz < k) {
                check = check -> next;
                ++sz;
            }
            if (sz < k) {
                dummy -> next = head;
                break;
            }
            sz = 0;
            while (sz < k) {
                ListNode* next = head -> next;
                head -> next = rev;
                rev = head;
                head = next;
                ++sz;
            }
            if (sz == k) {
                dummy -> next = rev;
                while (sz--) {
                    dummy = dummy -> next;
                }
            }
        }
        return ans -> next;
    }
};
