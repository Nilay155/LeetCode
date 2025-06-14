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
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            count += 1;
            temp = temp -> next;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int n = length(head);
        k %= n;

        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;

        int count = 1;
        ListNode* temp = head;

        while(n-count > k) {
            count += 1;
            temp = temp->next;
        }
        ListNode* curr = temp->next;
        temp -> next = nullptr;
        while(curr != NULL) {
            dummy -> next = curr;
            curr = curr -> next;
            dummy = dummy -> next;
        }

        dummy -> next = head;
        return ans -> next;

    }
};