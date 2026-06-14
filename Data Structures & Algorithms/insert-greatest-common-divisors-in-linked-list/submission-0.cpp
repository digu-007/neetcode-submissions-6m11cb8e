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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while (cur -> next) {
            ListNode* gcd = new ListNode(getGcd(cur -> val, cur -> next -> val), cur -> next);
            cur -> next = gcd;
            cur = gcd -> next;
        }
        return head;
    }

    int getGcd(int u, int v) {
        while (v > 0) {
            int temp = v;
            v = u % v;
            u = temp;
        }
        return u;
    }
};