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
    ListNode* reverseList(ListNode* cur) {
        // 1 -> 2 -> 3 -> 4
        ListNode* ans = nullptr;
        while (cur) {
            ListNode* nxt = cur -> next;
            cur -> next = ans;
            ans = cur;
            cur = nxt;
        }
        return ans;
    }
};
