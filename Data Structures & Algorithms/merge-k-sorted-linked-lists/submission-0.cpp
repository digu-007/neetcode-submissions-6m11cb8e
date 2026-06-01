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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) return nullptr;
        set<int> done;
        multiset<int> mm;
        while (done.size() < n) {
            for (int i = 0; i < n; ++i) {
                if (!lists[i]) {
                    done.insert(i);
                    cout << "Done: " << i << "\n";
                    continue;
                }
                cout << "Add: " << lists[i] -> val << "\n";
                mm.insert(lists[i] -> val);
                lists[i] = lists[i] -> next;
            }
        }
        for (auto &x: done) {
            cout << x << " ";
        }
        ListNode* ans = new ListNode(0);
        ListNode* dummy = ans;
        for (auto &x: mm) {
            dummy -> next = new ListNode(x);
            dummy = dummy -> next;
        }
        return ans -> next;
    }
};
