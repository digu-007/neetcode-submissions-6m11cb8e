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
        vector<int> res;
        while (done.size() < n) {
            for (int i = 0; i < n; ++i) {
                if (!lists[i]) {
                    done.insert(i);
                    continue;
                }
                res.push_back(lists[i] -> val);
                lists[i] = lists[i] -> next;
            }
        }
        sort(res.begin(), res.end());
        ListNode* ans = new ListNode(0);
        ListNode* dummy = ans;
        for (auto &x: res) {
            dummy -> next = new ListNode(x);
            dummy = dummy -> next;
        }
        return ans -> next;
    }
};
