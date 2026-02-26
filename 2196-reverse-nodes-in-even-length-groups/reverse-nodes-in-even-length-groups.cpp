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
    int getLinkedListLength(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while(curr) {
            curr = curr -> next;
            length += 1;
        }
        return length;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        int n = getLinkedListLength(head);

        ListNode* p = nullptr;
        ListNode* f = head -> next;
        ListNode* c = head;
        ListNode* last = nullptr;

        int groupCount = 1;

        while(c) {
            int sz = min(groupCount,n);
            int k = sz;
            ListNode* refHead = c;

            if(k % 2 == 0) {
                while(sz--) {
                    // Reverse the current group
                    ListNode* t = c;
                    c -> next = p;
                    c = f;
                    if(f) f = f -> next;
                    p = t;
                }
            } else {
                while(sz--) {
                    p = c;
                    c = f;
                    if(f) f = f -> next;
                }
            }
            if(groupCount > 1) {
                if(k % 2 == 0) {
                    last -> next = p;
                } else {
                    last -> next = refHead;
                }
            }
            n -= k;
            groupCount += 1;
            last = (k % 2 == 0) ? refHead : p;
            p = nullptr;
        }
        return head;

    }
};