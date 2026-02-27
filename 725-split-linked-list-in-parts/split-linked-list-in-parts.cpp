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
private:
    int getLinkedListLength(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while(curr) {
            curr = curr -> next;
            length += 1;
        }
        return length;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = getLinkedListLength(head);
        if(len == 0) return vector<ListNode*>(k);

        int q = len / k, r = len % k;
        vector<ListNode*> ans;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(k--) {
            ListNode* res = nullptr;
            int sz = q;

            while(sz--) {
                if(!res) res = curr;
                prev = curr;
                curr = curr -> next;
            }

            if(r) {
                if(!res) res = curr;
                prev = curr;
                curr = curr -> next;
                r--;
            }
            prev -> next = nullptr;
            ans.push_back(res);

        }
        return ans;
    }
};