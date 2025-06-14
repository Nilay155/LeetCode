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
    int length(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len += 1;
            temp = temp -> next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // if(k == 1) return head;
        int len = length(head);
        int no_of_iterations = len/k;
        int _k = 1;
        ListNode* lastHead = head;
        ListNode* lastTail = NULL;
        ListNode* ans = NULL;
        ListNode* prev = NULL;

        while(no_of_iterations >= _k) {
            // Reverse k-nodes
            prev = NULL;
            ListNode* curr = lastHead;
            ListNode* next = curr->next;
            int count = 1;
            ListNode* tail = NULL;

            while(count <= k) {
                if(count == 1) tail = curr;
                curr -> next = prev;
                prev = curr;
                curr = next;
                if(next != NULL)
                    next = next -> next;
                count += 1;
            } 
            if(_k == 1) ans = prev;
            lastHead = curr;
            if(lastTail != NULL) {
                lastTail -> next = prev;
            }
            lastTail = tail;
            _k += 1;
        }
        if(lastTail != NULL) {
            lastTail -> next = lastHead;
        }
        return ans;
    }
};