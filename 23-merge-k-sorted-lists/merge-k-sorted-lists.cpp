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
        ListNode* ans = new ListNode(-1e5);
        ListNode* res = ans;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;

        int n = lists.size();
        for(int i = 0 ; i < n ; i++) {
            if(lists[i] == nullptr) continue;
            pq.push({lists[i] -> val,lists[i]});
        }

        while(!pq.empty()) {
            auto [val,node] = pq.top(); pq.pop();
            ans -> next = node;
            ans = ans -> next;

            if(node -> next)
                pq.push({node -> next -> val,node -> next});
        }
        return res -> next;
    }
};